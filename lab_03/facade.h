#ifndef FACADE_H
#define FACADE_H

#include "Managers/UploadManager.h"
#include "Managers/scenemanager.h"
#include "Managers/drawmanager.h"
#include "Managers/transformmanager.h"

class Facade {
public:
    Facade();

    ~Facade() = default;
    // friend conCommand();
private:
    UploadManager UploadMan;
    SceneManager SceneMan;
    DrawManager DrawMan;
    TransformManager TransformMan;
};

#endif // FACADE_H
