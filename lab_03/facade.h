#ifndef FACADE_H
#define FACADE_H

#include "Managers/UploadManager.h"
#include "Managers/drawmanager.h"
#include "Managers/scenemanager.h"
#include "Managers/transformmanager.h"

class Facade
{
public:
    Facade();

    void execute(UploadCommand &);

    void execute(DrawCommand &);

    void execute(TransformMoveCommand &, ComponentName);

    void execute(TransformRotateCommand &, ComponentName);

    void execute(TransformScaleCommand &, ComponentName);

    void execute(ChangeCurComponentCommand &, ComponentName);

private:
    UploadManager UploadMan;
    SceneManager SceneMan;
    DrawManager DrawMan;
    TransformManager TransformMan;
};

#endif // FACADE_H
