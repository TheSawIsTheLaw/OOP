#ifndef FACADE_H
#define FACADE_H

#include "Managers/UploadManager.hpp"
#include "Managers/drawmanager.hpp"
#include "Managers/scenemanager.hpp"
#include "Managers/transformmanager.hpp"

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
