#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene/scene.h"
#include "managerbase.h"

class SceneManager : public ManagerBase
{
public:
    SceneManager();

    virtual ~SceneManager() = default;

private:
    Scene scene;
    size_t currentCam = 0, currentModel = 0;
};

#endif // SCENEMANAGER_H
