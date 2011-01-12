
#define __MACOS__
#include <EDSDK.h>
#include <EDSDKTypes.h>

#include <iostream>

// g++ -g -arch i386 -I./EDSDK/Header -framework EDSDK -o eosctrl main.cpp

using namespace std;

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
        downloadImage(object);
        break;
        
    default:
        break;
    }
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
    cout << "STATE EVENT" << (int) param << endl;
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
        err = EdsGetChildAtIndex(cameraList,
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


int main( int argc, char** argv ) { 

    EdsError err = EDS_ERR_OK; 
    EdsCameraRef camera = NULL; 
    bool isSDKLoaded = false;
    
    // Initialize SDK 
    err = EdsInitializeSDK(); 
    if ( err == EDS_ERR_OK ) {
        isSDKLoaded = true;
    }
    
    // Get camera
    if ( err == EDS_ERR_OK ) {
        err = getCamera( &camera );
    }

    // Set event handler 
    if ( err == EDS_ERR_OK ) {
        err = EdsSetObjectEventHandler( camera, 
                                        kEdsObjectEvent_All,
                                        handleObjectEvent,
                                        NULL);
    }

    // Set event handler 

    if ( err == EDS_ERR_OK ) {
        err = EdsSetPropertyEventHandler( camera,
                                          kEdsPropertyEvent_All,
                                          handlePropertyEvent, 
                                          NULL );
    }

    // Set event handler 

    if ( err == EDS_ERR_OK ) {
        err = EdsSetCameraStateEventHandler( camera,
                                             kEdsStateEvent_All,
                                             handleStateEvent, 
                                             NULL );
    }

    // Open session with camera
    if ( err == EDS_ERR_OK ) {
        err = EdsOpenSession(camera);
    }

    ///// // do something ////
    // Close session with camera 
    if ( err == EDS_ERR_OK ) {
        err = EdsCloseSession(camera);
    }

    // Release camera 
    if ( camera != NULL ) {
        EdsRelease(camera);
    }
    
    // Terminate SDK 
    if ( isSDKLoaded ) {
        EdsTerminateSDK();
    }    
    
    return 0;
}
