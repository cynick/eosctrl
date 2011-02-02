#ifndef __SHOOT_H__
#define __SHOOT_H__


#include <EDSDKTypes.h>

class StateHolder { 

public: 
    StateHolder( bool _sdkInitialized, 
                 const EdsCameraRef _camera = NULL ) :
        sdkInitialized( _sdkInitialized ), 
        camera( _camera ) {
        
        if ( sdkInitialized ) { 
            cout <<  "SDK initialized" << endl;
        }
    }
    
    ~StateHolder() {
        
        if ( sdkInitialized ) { 
            cout << "Terminating SDK" << endl;
            EdsTerminateSDK();
        }    
    }
    
    EdsCameraRef getCameraRef() const { return camera; }
    
private:
    bool sdkInitialized;
    const EdsBaseRef camera;
};

void shoot( StateHolder* );

#endif /*__SHOOT_H__*/
