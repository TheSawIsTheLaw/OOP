#ifndef FACADE_H
#define FACADE_H

#include "Managers/UploadManager.h"
#include "Managers/scenemanager.h"

class Facade{
public:
//    CommandBase Command();
private:
    UploadManager Upload;
    SceneManager Scene;
//    DrawManager Draw;
//    TransformManager Transform;
};

#endif // FACADE_H
