
#include <CoreFoundation/CoreFoundation.h>

#include <EDSDKTypes.h>
#include <EDSDKErrors.h>
#include <EDSDK.h>

#include <iostream>
#include <pthread.h>
#include <unistd.h>

#include "err.h"
#include "util.h"
#include "shoot.h"

// Strange though it may seem, there doesn't seem 
// to be a header anywhere that declares this function.

extern "C" {
    void RunApplicationEventLoop();
}

using namespace std;

static int _argc;
static char** _argv;
static bool isSDKLoaded;

EdsBaseRef camera;


static EdsError downloadImage( EdsDirectoryItemRef directoryItem ) {
    
    EdsError err = EDS_ERR_OK;
    EdsStreamRef stream = NULL;

    EdsDirectoryItemInfo dirItemInfo; 
    
    err = EdsGetDirectoryItemInfo( directoryItem, &dirItemInfo );
    
    // Create file stream for transfer destination 
    if ( err == EDS_ERR_OK ) {
        err = EdsCreateFileStream( dirItemInfo.szFileName,
                                   kEdsFileCreateDisposition_CreateAlways,
                                   kEdsAccess_ReadWrite, 
                                   &stream );
    }
    
    if ( err == EDS_ERR_OK ) {
        err = EdsDownload( directoryItem, dirItemInfo.size, stream);
        // Issue notification that download is complete 
        if ( err == EDS_ERR_OK ) {
            err = EdsDownloadComplete( directoryItem );
        }
    }

    // Release stream 
    if ( stream != NULL ) {
        EdsRelease( stream );
        stream = NULL;
    } 

    return err;
}

EdsError EDSCALLBACK handleObjectEvent( EdsObjectEvent event, 
                                        EdsBaseRef object,
                                        EdsVoid* context ) {
    switch ( event ) {
    case kEdsObjectEvent_DirItemRequestTransfer:
        cout << "Handling " << getObjectEventName( event ) << " event" << endl;
        downloadImage( object );
        break;
        
    default:
        cout << "No handler for object event " << 
            getObjectEventName( event ) << endl;
        break;
    }
    
    return EDS_ERR_OK;
}

EdsError EDSCALLBACK handlePropertyEvent( EdsPropertyEvent event,
                                          EdsPropertyID property,
                                          EdsUInt32 param,
                                          EdsVoid* context ) {
    cout << "Received " << getPropertyEventName( event ) << " property event" << endl;
    return EDS_ERR_OK;
}

EdsError EDSCALLBACK handleStateEvent( EdsStateEvent event, 
                                       EdsUInt32 param,
                                       EdsVoid* context ) {
    
    cout << "Received " << getStateEventName( event ) << " state event" << endl;
    return EDS_ERR_OK;
}

static EdsError getCamera( EdsCameraRef* camera ) {
    
    EdsError err = EDS_ERR_OK;
    EdsCameraListRef cameraList = NULL; 
    EdsUInt32 count = 0;
    
    // Get camera list
    err = EdsGetCameraList( &cameraList );
    
    // Get number of cameras
    if ( err == EDS_ERR_OK ) {
        err = EdsGetChildCount( cameraList, &count );
    }
    
    if ( count == 0 ) {
        err = EDS_ERR_DEVICE_NOT_FOUND;
    }
    
    // Get first camera retrieved 
    if ( err == EDS_ERR_OK ) {
        err = EdsGetChildAtIndex( cameraList,
                                  0,
                                  camera );
    }

    // Release camera list 
    if ( cameraList != NULL ) {
        EdsRelease( cameraList );
    }
}


static void* run( void* arg );



static void shoot();

static void* run( void* ) {
    
    shoot();
    return NULL;
}    


static void shoot() { 

    sleep(1);

    EdsError err = EDS_ERR_OK; 

    if ( (err = EdsOpenSession(camera)) != EDS_ERR_OK ) { 
        cout << "Failed to open session: " << getErrorString( err ) << endl;
        return;
    }

    sleep(10);
    //dumpProperties();
    
    EdsSaveTo saveTo = kEdsSaveTo_Host;
    
    cout << "Setting SaveTo" << endl;

    if ( (err = EdsSetPropertyData( camera, kEdsPropID_SaveTo, 2, sizeof(saveTo), &saveTo )) 
         != EDS_ERR_OK ) {
        cout << "Failed to set kEdsPropID_saveTo: " << getErrorString( err ) << endl;
        return;
    }

    if ( (err = EdsGetPropertyData( camera, kEdsPropID_SaveTo, 0, sizeof(saveTo), &saveTo ))
         != EDS_ERR_OK ) { 
        cout << "Failed to get kEdsPropID_saveTo: " << getErrorString( err ) << endl;
        return;
    }
    
    cout << "Current value of kEdsPropID_SaveTo is " << saveTo << endl;

    cout << "Opened session" << endl;

    cout << "Locking camera" << endl;    
    
    if ( (err = EdsSendStatusCommand( camera, kEdsCameraStatusCommand_UILock, 0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to lock camera: " << getErrorString( err ) << endl;    
        return;
    }
    
    cout << "Locked camera" << endl;

    cout << "Taking picture" << endl;    
    if ( (err = EdsSendCommand( camera, kEdsCameraCommand_TakePicture, 0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to take picture: " << getErrorString( err ) << endl;    
    }

    cout << "Unlocking camera" << endl;    
    if ( (err = EdsSendStatusCommand( camera, kEdsCameraStatusCommand_UIUnLock, 0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to unlock" << endl;
        return;
    }

    cout << "Unlocked camera" << endl;    

    cout << "OK" << endl;
}

static EdsError findCamera() { 
    camera = NULL;
    EdsError err = getCamera( &camera );
    
    if ( err != EDS_ERR_OK ) { 
        cout << "Failed to find camera" << endl;
        return err;
    } 
    
    cout << "Camera found: " << camera << endl;
    
    return err;
}

static void setEventHandlers() { 
    EdsError err = EDS_ERR_OK;
    if ( (err = EdsSetObjectEventHandler( camera, 
                                          kEdsObjectEvent_All,
                                          handleObjectEvent,
                                          NULL)) != EDS_ERR_OK ) {
        cout << "Failed to set object event handler: " << getErrorString( err ) << endl;
        return;
    }
    
    if ( (err = EdsSetPropertyEventHandler( camera,
                                            kEdsPropertyEvent_All,
                                            handlePropertyEvent, 
                                            NULL )) != EDS_ERR_OK ) { 
        cout << "Failed to set property event handler: " << getErrorString( err ) << endl;
        return;
    }
    
    if ( (err = EdsSetCameraStateEventHandler( camera,
                                               kEdsStateEvent_All,
                                               handleStateEvent, 
                                               NULL )) != EDS_ERR_OK ) { 
        cout << "Failed to set state event handler: " << getErrorString( err ) << endl;
        return;
    }
}

static void closeSession() { 

    cout << "Closing session" << endl;    
    EdsError err = EDS_ERR_OK;
    
    if ( (err = EdsCloseSession(camera)) != EDS_ERR_OK ) {
        cout << "Failed to close session: " << getErrorString( err ) << endl;
    }
}

void cleanup() { 
    closeSession();

    if ( isSDKInitialized ) { 

        cout << "Terminating SDK" << endl;
        EdsError err = EdsTerminateSDK();
        if ( err != EDS_ERR_OK ) { 
            cout << "Failed to terminate SDK: " << getErrorString( err ) << endl;
        }

        cout << "Terminated SDK" << endl;
    }
}

int main( int argc, char** argv ) { 
    
    _argc = argc;
    _argv = argv;
    
    const char* prog = argv[0];
    
    EdsError err = EDS_ERR_OK; 
    isSDKLoaded = false;
    
    err = EdsInitializeSDK(); 
    if ( err == EDS_ERR_OK ) {
        isSDKLoaded = true;
    } else { 
        cout << "Failed to load SDK" << endl;
        return 1;
    }
    
    err = findCamera();
    if ( err != EDS_ERR_OK ) { 
        exit(1);
    }
    
    setEventHandlers();
    
    pthread_t thread;
    int status = pthread_create( &thread, NULL, run, NULL );
    if ( status != 0 ) { 
        cerr << "Failed to create run thread" << endl;
    }

    cout << "Starting event loop" << endl;
    RunApplicationEventLoop();
    
    // We will never get to here; the run function 
    // will clean up all state and make an explicit call 
    // to exit.
    
    exit(0);
}
