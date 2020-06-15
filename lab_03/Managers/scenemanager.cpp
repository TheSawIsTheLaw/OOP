#include "scenemanager.h"

void SceneManager::addComponent(std::shared_ptr<Component> component, ComponentName name)
{
    scene.addComponent(component, name);
}

void SceneManager::delComponent(ComponentName name)
{
    size_t index = name == SCENE ? currentScene : (name == MODEL ? currentModel : currentCam);
    auto iter = scene.getIter(index, name);
    scene.delComponent(iter, name);
}

std::shared_ptr<Component> SceneManager::getComponent(ComponentName name)
{
    std::shared_ptr<Component> res;
    res = name == SCENE ? scene.getComponent(currentScene, name)
                        : (name == MODEL ? scene.getComponent(currentModel, name)
                                         : scene.getComponent(currentCam, name));
    return res;
}
