
#include "shoot.h"
#include "err.h"
#include "util.h"

#include <unistd.h>
#include <pthread.h>
#include <iostream>
#include <string>

#include <EDSDKTypes.h>
#include <EDSDKErrors.h>
#include <EDSDK.h>

extern pthread_mutex_t lock;
extern pthread_cond_t cond;

using namespace std;

EdsError downloadImage( EdsDirectoryItemRef directoryItem,
                        StateHolder* holder ) {

    EdsError err = EDS_ERR_OK;
    EdsStreamRef stream = NULL;

    EdsDirectoryItemInfo dirItemInfo;

    err = EdsGetDirectoryItemInfo( directoryItem, &dirItemInfo );
    if ( err != EDS_ERR_OK ) {
        cout << "EdsGetDirectoryItemInfo failed with " <<
            getErrorString(err) << endl;
        return err;
    }

    string name( dirItemInfo.szFileName );

    size_t index = name.find( '.' );
    if ( index != string::npos ) {
        name.replace( 0, index, holder->getFilename() );
    }

    // Create file stream for transfer destination
    err = EdsCreateFileStream( name.c_str(),
                               kEdsFileCreateDisposition_CreateAlways,
                               kEdsAccess_ReadWrite,
                               &stream );

    if ( err != EDS_ERR_OK ) {
        cout << "EdsCreateFileStream failed with " <<
            getErrorString(err) << endl;
        return err;
    }

    err = EdsDownload( directoryItem, dirItemInfo.size, stream);
    if ( err != EDS_ERR_OK ) {
        cout << "EdsDownload failed with " <<
            getErrorString(err) << endl;
        return err;
    }

    err = EdsDownloadComplete( directoryItem );
    if ( err != EDS_ERR_OK ) {
        cout << "EdsDownloadComplete failed with " << err << endl;
        return err;
    }

    // Release stream
    if ( stream != NULL ) {
        EdsRelease( stream );
        stream = NULL;
    }

    sleep(1);

    int status = pthread_mutex_lock( &lock );

    if ( status != 0 ) {
        cout << "Failed to obtain lock" << endl;
        exit(status);
    }

    cout << "Download of " << name.c_str() << " complete, setting framecount to "  <<
        (holder->getFrameCount() +1) << endl;

    holder->setFrameCount( holder->getFrameCount() +1 );

    status = pthread_cond_signal( &cond );
    if ( status != 0 ) {
        cout << "Failed to signal cond: " << status << endl;
    }

    status = pthread_mutex_unlock( &lock );

    if ( status != 0 ) {
        cout << "Failed to release lock: " << status << endl;
    }

    return err;
}

static EdsError closeSession( EdsCameraRef camera ) {

    cout << "Closing session" << endl;
    EdsError err = EDS_ERR_OK;

    if ( (err = EdsCloseSession(camera)) != EDS_ERR_OK ) {
        cout << "Failed to close session: " << getErrorString( err ) << endl;
        return err;
    }

    cout << "Session is closed" << endl;
    return EDS_ERR_OK;
}

EdsError cleanup( StateHolder* holder ) {
    EdsError err = closeSession( holder->getCameraRef() );

    if ( err != EDS_ERR_OK ) {
        return err;
    }

    if ( holder->isSdkInitialized() ) {
        cout << "Terminating SDK" << endl;
        EdsError err = EdsTerminateSDK();
        if ( err != EDS_ERR_OK ) {
            cout << "Failed to terminate SDK: " << getErrorString( err ) << endl;
            return err;
        }

        cout << "Terminated SDK" << endl;
    }

    return EDS_ERR_OK;
}

EdsError shoot( StateHolder* holder ) {

    sleep(1);

    EdsError err = EDS_ERR_OK;

    EdsCameraRef camera = holder->getCameraRef();

    if ( (err = EdsOpenSession(camera)) != EDS_ERR_OK ) {
        cout << "Failed to open session: " << getErrorString( err ) << endl;
        return err;
    }

    dumpProperties( camera );

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
      return err;
    }

    if ( (err = EdsGetPropertyData( camera,
                                    kEdsPropID_SaveTo,
                                    0,
                                    sizeof(saveTo), &saveTo ))
         != EDS_ERR_OK ) {
        cout << "Failed to get kEdsPropID_saveTo: " <<
            getErrorString( err ) << endl;
        return err;
    }

    cout << "Current value of kEdsPropID_SaveTo is " << saveTo << endl;

    cout << "Opened session" << endl;

    cout << "Locking camera" << endl;

    if ( (err = EdsSendStatusCommand( camera,
                                      kEdsCameraStatusCommand_UILock,
                                      0)) !=
         EDS_ERR_OK ) {
        cout << "Failed to lock camera: " << getErrorString( err ) << endl;
        return err;
    }

    cout << "Locked camera" << endl;

    cout << "Taking picture" << endl;
    if ( (err = EdsSendCommand( camera,
                                kEdsCameraCommand_TakePicture,
                                0)) !=
         EDS_ERR_OK ) {
        cout << "Failed to take picture: " << getErrorString( err ) << endl;
        return err;
    }

    cout << "Unlocking camera" << endl;
    if ( (err = EdsSendStatusCommand( camera,
                                      kEdsCameraStatusCommand_UIUnLock,
                                      0)) !=
         EDS_ERR_OK ) {
        cout << "Failed to unlock" << endl;
        return err;
    }

    cout << "Unlocked camera" << endl;

    struct timespec ts;
    ts.tv_sec = time(NULL) + 2;

    int status = pthread_mutex_lock( &lock );
    if ( status != 0 ) {
        cout << "Failed to obtain mutex" << endl;
    }

    while ( holder->getFrameCount() != holder->getExpectedFrameCount() ) {

        cout << "Waiting for frames" << endl;

        status = pthread_cond_wait( &cond, &lock );

        cout << "Finished waiting for frames" << endl;

        if ( status == ETIMEDOUT ) {
            continue;
        }

        if ( status != 0 ) {
            cout << "Timed wait failed" << endl;
        }
    }

    status = pthread_mutex_unlock( &lock );

    if ( status != 0 ) {
        cout << "Failed to unlock mutex" << endl;
    }

    cout << "Received " << holder->getFrameCount() << " frames, shutting down" << endl;

    return EDS_ERR_OK;
}

