#ifndef __SHOOT_H__
#define __SHOOT_H__


#include <EDSDKTypes.h>

class StateHolder { 
    
public: 
    StateHolder() : sdkInitialized(false), cameraRef(0), frameCount(0) {}
    
    ~StateHolder() {}
    
    bool isSdkInitialized() const { 
        return sdkInitialized;
    }
    
    void setSdkInitialized( bool flag ) { 
        this->sdkInitialized = flag;
    }
    
    EdsCameraRef getCameraRef() const { return cameraRef; }
    
    void setCameraRef( EdsCameraRef cameraRef ) {
        this->cameraRef = cameraRef;
    }

    int getFrameCount() const { 
        return frameCount;
    }

    void setFrameCount( int frameCount ) { 
        this->frameCount = frameCount;
    }
    
private:
    bool sdkInitialized;
    EdsCameraRef cameraRef;
    int frameCount;
};

void shoot( StateHolder* );



#endif /*__SHOOT_H__*/
