#ifndef FACADE_H
#define FACADE_H

#include "Managers/UploadManager.h"
#include "Managers/scenemanager.h"
#include "Managers/drawmanager.h"
#include "Managers/transformmanager.h"

class Facade{
public:
//    CommandBase Command();
private:
    UploadManager Upload;
    SceneManager Scene;
    DrawManager Draw;
    TransformManager Transform;
};

#endif // FACADE_H
