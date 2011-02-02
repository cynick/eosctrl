
#include "shoot.h"
#include <unistd.h>

#include <EDSDKTypes.h>
#include <EDSDKErrors.h>
#include <EDSDK.h>

void shoot( StateHolder* state ) { 

    sleep(1);

    EdsError err = EDS_ERR_OK; 

    EdsCameraRef camera = state->getCameraRef();

    if ( (err = EdsOpenSession(camera)) != EDS_ERR_OK ) { 
        cout << "Failed to open session: " << getErrorString( err ) << endl;
        return;
    }

    sleep(10);
    //dumpProperties( camera );
    
    EdsSaveTo saveTo = kEdsSaveTo_Host;
    
    cout << "Setting SaveTo" << endl;
    
    if ( (err = EdsSetPropertyData( camera, 
                                    kEdsPropID_SaveTo, 
                                    0, 
                                    sizeof(saveTo), 
                                    &saveTo )) 
         != EDS_ERR_OK ) {
        cout << "Failed to set kEdsPropID_saveTo: " << 
            getErrorString( err ) << endl;
        return;
    }
    
    if ( (err = EdsGetPropertyData( camera, 
                                    kEdsPropID_SaveTo, 
                                    0, 
                                    sizeof(saveTo), &saveTo ))
         != EDS_ERR_OK ) { 
        cout << "Failed to get kEdsPropID_saveTo: " << 
            getErrorString( err ) << endl;
        return;
    }
    
    cout << "Current value of kEdsPropID_SaveTo is " << saveTo << endl;

    cout << "Opened session" << endl;

    cout << "Locking camera" << endl;    
    
    if ( (err = EdsSendStatusCommand( camera, 
                                      kEdsCameraStatusCommand_UILock, 
                                      0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to lock camera: " << getErrorString( err ) << endl;    
        return;
    }
    
    cout << "Locked camera" << endl;
    
    cout << "Taking picture" << endl;    
    if ( (err = EdsSendCommand( camera, 
                                kEdsCameraCommand_TakePicture, 
                                0)) !=
         EDS_ERR_OK ) { 
        cout << "Failed to take picture: " << getErrorString( err ) << endl;    
    }
    
    cout << "Unlocking camera" << endl;    
    if ( (err = EdsSendStatusCommand( camera, 
                                      kEdsCameraStatusCommand_UIUnLock, 
                                      0)) !=
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
