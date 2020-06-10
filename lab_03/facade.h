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

    ~Facade() = default;

    template<typename Command>
    void execute(Command);

   private:
    UploadManager UploadMan;
    SceneManager SceneMan;
    DrawManager DrawMan;
    TransformManager TransformMan;
};

#endif // FACADE_H
