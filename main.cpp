
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

StateHolder holder;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

extern EdsError downloadImage( EdsDirectoryItemRef, StateHolder* );


EdsError EDSCALLBACK handleObjectEvent( EdsObjectEvent event, 
                                        EdsBaseRef object,
                                        EdsVoid* context ) {
    switch ( event ) {
    case kEdsObjectEvent_DirItemRequestTransfer:
        cout << "Handling " << getObjectEventName( event ) << " event" << endl;
        downloadImage( object, 
                       reinterpret_cast<StateHolder*>( context ) );
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

static EdsError findCamera( StateHolder* holder ) {
    
    EdsError err = EDS_ERR_OK;
    EdsCameraListRef cameraList = NULL; 
    EdsUInt32 count = 0;
    EdsCameraRef camera;
    
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
                                  &camera );
    }

    // Release camera list 
    if ( cameraList != NULL ) {
        EdsRelease( cameraList );
    }

    if ( err != EDS_ERR_OK ) { 
        cout << "Failed to find camera" << endl;
        return err;
    } 

    holder->setCameraRef( camera );
    
    cout << "Camera found: " << holder->getCameraRef() << endl;

    return err;
}


static void setEventHandlers( StateHolder* holder ) { 
    EdsCameraRef camera = holder->getCameraRef();
    
    EdsError err = EDS_ERR_OK;
    if ( (err = EdsSetObjectEventHandler( camera, 
                                          kEdsObjectEvent_All,
                                          handleObjectEvent,
                                          holder )) != EDS_ERR_OK ) {
        cout << "Failed to set object event handler: " << getErrorString( err ) << endl;
        return;
    }
    
    if ( (err = EdsSetPropertyEventHandler( camera,
                                            kEdsPropertyEvent_All,
                                            handlePropertyEvent, 
                                            holder )) != EDS_ERR_OK ) { 
        cout << "Failed to set property event handler: " << getErrorString( err ) << endl;
        return;
    }
    
    if ( (err = EdsSetCameraStateEventHandler( camera,
                                               kEdsStateEvent_All,
                                               handleStateEvent, 
                                               holder )) != EDS_ERR_OK ) { 
        cout << "Failed to set state event handler: " << getErrorString( err ) << endl;
        return;
    }
}


static void* run( void* arg ) { 

    StateHolder* holder = reinterpret_cast<StateHolder*>(arg);
    
    shoot( holder );
}


int main( int argc, char** argv ) { 
    
    const char* prog = argv[0];
    
    memset( &holder, 0, sizeof( StateHolder ) );
    
    char buf[20];
    sprintf( buf, "0x%x", (int) &holder );
    cout << "State holder has address " << buf << endl;
    
    holder.setFilename( argv[1] );

    EdsError err = EDS_ERR_OK; 
    
    err = EdsInitializeSDK(); 
    if ( err != EDS_ERR_OK ) {
        cout << "Failed to load SDK" << endl;
        exit(1);
    }
    
    holder.setSdkInitialized( true );
    
    err = findCamera( &holder );
    if ( err != EDS_ERR_OK ) { 
        cout << "Failed to find camera" << endl;
        exit(1);
    }
    
    setEventHandlers( &holder );
    
    pthread_t thread;
    int status = pthread_create( &thread, NULL, run, &holder );
    if ( status != 0 ) { 
        cerr << "Failed to create run thread" << endl;
        exit(1);
    }
    
    cout << "Starting event loop" << endl;
    RunApplicationEventLoop();
    
    // We will never get to here; the run function 
    // will clean up all state and make an explicit call 
    // to exit.
    
    exit(0);
}
