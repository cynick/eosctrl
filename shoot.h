#ifndef __SHOOT_H__
#define __SHOOT_H__


#include <EDSDKTypes.h>

class StateHolder { 
    
public: 
    StateHolder() : sdkInitialized(false), 
                    cameraRef(0), 
                    frameCount(0), 
                    filename(0) {}
    
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

    const char* getFilename() const { 
        return filename;
    }

    void setFilename( const char* filename ) { 
        this->filename = filename;
    }
    
private:
    bool sdkInitialized;
    EdsCameraRef cameraRef;
    int frameCount;
    const char* filename;

};

void shoot( StateHolder* );



#endif /*__SHOOT_H__*/