
#define __APPLE__ 1

#include <EDSDK.h>
#include <EDSDKTypes.h>
#include <EDSDKErrors.h>

#include <pthread.h>

#include <string>
using std::string;
string eds_error_tostring( int error );

//#include "err.h"

#include <iostream>

extern "C" {
    void RunApplicationEventLoop();
}

// g++ -g -arch i386 -I./EDSDK/Header -framework EDSDK -o eosctrl main.cpp

using namespace std;

static int _argc;
static char** _argv;

class SdkTerminator { 
 public: 

    SdkTerminator( bool _loaded ) : loaded( _loaded ) {
        if ( loaded ) { 
            cout <<  "SDK initialized" << endl;
        }
    }
    
    ~SdkTerminator() {
        if ( loaded ) { 
            cout << "Terminating SDK" << endl;
            EdsTerminateSDK();
        }    
    }
    
 private:
    bool loaded;
};

class Camera { 

};

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
            err = EdsDownloadComplete(directoryItem);
        }
    }

    // Release stream 
    if ( stream != NULL ) {
        EdsRelease(stream);
        stream = NULL;
    } 

    return err;
}

EdsError EDSCALLBACK handleObjectEvent( EdsObjectEvent event, 
                                        EdsBaseRef object,
                                        EdsVoid* context ) {
    switch ( event ) {
    case kEdsObjectEvent_DirItemRequestTransfer: 
        cout << "DOWNLOADING" << endl;
        downloadImage(object);
        break;
        
    default:
        cout << "Unhandled event:" << event << endl;
        break;
    }

    return EDS_ERR_OK;
}

EdsError EDSCALLBACK handlePropertyEvent( EdsPropertyEvent event,
                                          EdsPropertyID property,
                                          EdsUInt32 param,
                                          EdsVoid* context ) {
    cout << "PROPERTY EVENT" << (int) property << endl;
}

EdsError EDSCALLBACK handleStateEvent( EdsStateEvent event, 
                                       EdsUInt32 param,
                                       EdsVoid* context ) {
    switch ( event ) { 

    case kEdsStateEvent_Shutdown:
        cout << "Handle state event: " << "kEdsStateEvent_Shutdown" << endl;
        break;
        
    case kEdsStateEvent_JobStatusChanged:
        cout << "Handle state event: " << "kEdsStateEvent_JobStatusChanged" << endl;
        break;
        
    case kEdsStateEvent_WillSoonShutDown:
        cout << "Handle state event: " << "kEdsEvent_WillSoonShutDown" << endl;
        break;
        
    case kEdsStateEvent_ShutDownTimerUpdate:
        cout << "Handle state event: " << "kEdsStateEvent_ShutDownTimerUpdate" << endl;
        break;
        
    case kEdsStateEvent_CaptureError:
        cout << "Handle state event: " << "kEdsStateEvent_CaptureError" << endl;
        break;
        
    case kEdsStateEvent_InternalError:
        cout << "Handle state event: " << "kEdsStateEvent_InternalError" << endl;
        break;
        
    case kEdsStateEvent_AfResult:
        cout << "Handle state event: " << "kEdsStateEvent_AfResult" << endl;
        break;
        
    case kEdsStateEvent_BulbExposureTime:
        cout << "Handle state event: " << "kEdsStateEvent_BulbExposureTime" << endl;
        break;
        
    default:
        cout << "UNKNOWN state event: " << event << endl;
    }

    return EDS_ERR_OK;
}

static EdsError getCamera( EdsCameraRef *camera ) {
    EdsError err = EDS_ERR_OK;
    EdsCameraListRef cameraList = NULL; 
    EdsUInt32 count = 0;

    // Get camera list e
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

static EdsError getVolume( EdsCameraRef camera, EdsVolumeRef* volume ) {
    EdsError err = EDS_ERR_OK; 
    EdsUInt32 count = 0;

    // Get the number of camera volumes 
    err = EdsGetChildCount(camera, &count);
    if ( err == EDS_ERR_OK && count == 0 ) {
        err = EDS_ERR_DIR_NOT_FOUND;
    }
    
    // Get initial volume 
    if ( err == EDS_ERR_OK ) {
        err = EdsGetChildAtIndex( camera, 0, volume );
    }
    
    return err;
}


static void* run( void* arg );



static void shoot();

static void* run( void* ) {
    
    shoot();
    exit(0);
    return NULL;
}    

static void shoot() { 
    sleep(1);
    
    cout << "Running EDSDK code" << endl;

    EdsError err = EDS_ERR_OK; 

#if 0     

    bool isSDKLoaded = false;
    
    err = EdsInitializeSDK(); 
    if ( err == EDS_ERR_OK ) {
        isSDKLoaded = true;
    } else { 
        cout << "Failed to load SDK" << endl;
        return;
    }
    
    SdkTerminator terminator( isSDKLoaded );
#endif
    
    EdsCameraRef camera = NULL; 
    err = getCamera( &camera );
    
    if ( err != EDS_ERR_OK ) { 
        cout << "Failed to find camera" << endl;
        return;
    } 
    
    cout << "Camera found" << endl;

    if ( (err = EdsSetObjectEventHandler( camera, 
                                          kEdsObjectEvent_All,
                                          handleObjectEvent,
                                          NULL)) != EDS_ERR_OK ) {
        cout << "Failed to set object event handler: " << err << endl;
        return;
    }

    if ( (err = EdsSetPropertyEventHandler( camera,
                                            kEdsPropertyEvent_All,
                                            handlePropertyEvent, 
                                            NULL )) != EDS_ERR_OK ) { 
        cout << "Failed to set property event handler: " << err << endl;
        return;
    }

    if ( (err = EdsSetCameraStateEventHandler( camera,
                                               kEdsStateEvent_All,
                                               handleStateEvent, 
                                               NULL )) != EDS_ERR_OK ) { 
        cout << "Failed to set state event handler: " << err << endl;
        return;
    }
    
    cout << "Opening session" << endl;
    
    if ( (err = EdsOpenSession(camera)) != EDS_ERR_OK ) { 
        cout << "Failed to open session: " << err << endl;
        return;
    }
    
    cout << "Opened session" << endl;

    cout << "Locking camera" << endl;    
    
    if ( (err = EdsSendStatusCommand( camera, kEdsCameraStatusCommand_UILock, 0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to lock camera: " << err << endl;    
        return;
    }
    
    cout << "Taking picture" << endl;    
    if ( (err = EdsSendCommand( camera, kEdsCameraCommand_TakePicture, 0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to take picture: " << err << endl;    
    }

    sleep(5);

    cout << "Unlocking camera" << endl;    
    if ( (err = EdsSendStatusCommand( camera, kEdsCameraStatusCommand_UIUnLock, 0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to unlock" << endl;
        return;
    }
    
    cout << "Unlocked camera" << endl;    
    cout << "Closing session" << endl;    
    
    if ( (err = EdsCloseSession(camera)) != EDS_ERR_OK ) {
        cout << "Failed to close session: " << err << endl;
    }
    
    cout << "OK" << endl;
}


int main( int argc, char** argv ) { 

    _argc = argc;
    _argv = argv;
    
    pthread_t thread;
    void* res;

#if 1
    EdsError err = EDS_ERR_OK; 
    bool isSDKLoaded = false;
    
    err = EdsInitializeSDK(); 
    if ( err == EDS_ERR_OK ) {
        isSDKLoaded = true;
    } else { 
        cout << "Failed to load SDK" << endl;
        return 1;
    }
    
    SdkTerminator terminator( isSDKLoaded );

    int status = pthread_create( &thread, NULL, run, NULL );
    if ( status != 0 ) { 
        cerr << "Failed to create thread" << endl;
    }

    cout << "Starting event loop" << endl;
    RunApplicationEventLoop();
    
    status = pthread_join( thread, &res );
    if ( res == NULL ) { 
        return 0;
    }
#else
    run(NULL);
#endif

    return 1;
}
