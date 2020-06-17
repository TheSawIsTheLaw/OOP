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

void SceneManager::changeCurComp(int moveTo, ComponentName name)
{
    if (name == SCENE)
    {
        currentScene += moveTo;
        currentCam = 0;
        currentModel = 0;
    }
    else if (name == MODEL)
        currentModel += moveTo;
    else if (name == CAMERA)
        currentCam += moveTo;
    else
    {
        time_t curTime = time(NULL);
        throw BadComponentName(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
}
