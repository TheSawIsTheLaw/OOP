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

    QGraphicsScene *execute(UploadCommand &);

    QGraphicsScene *execute(DrawCommand &);

    QGraphicsScene *execute(TransformModelMoveCommand &);

    QGraphicsScene *execute(TransformModelRotateCommand &);

    QGraphicsScene *execute(TransformModelScaleCommand &);

private:
    UploadManager UploadMan;
    SceneManager SceneMan;
    DrawManager DrawMan;
    TransformManager TransformMan;
};

#endif // FACADE_H
