#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene/scene.h"
#include "managerbase.h"

class SceneManager : public ManagerBase
{
public:
    void addComponent(std::shared_ptr<Component> component, ComponentName name);
    void delComponent(ComponentName name);
    std::shared_ptr<Component> getComponent(ComponentName name);
    void changeCurComp(int moveTo, ComponentName name);

private:
    Scene scene;
    size_t currentCam = 0, currentModel = 0, currentScene = 0;
};

#endif // SCENEMANAGER_H
