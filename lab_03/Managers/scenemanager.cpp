#include "scenemanager.h"

void SceneManager::addComponent(std::shared_ptr<Component> component, ComponentName name)
{
    scene.addComponent(component, name);
    currentCam = 0;
    currentModel = 0;
    currentScene += 1;
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
        if (currentScene > scene.compAmount(SCENE))
            currentScene = 0;
        currentCam = 0;
        currentModel = 0;
        scene.setScene(currentScene);
    }
    else if (name == MODEL)
    {
        currentModel += moveTo;
        if (currentModel >= scene.compAmount(MODEL))
            currentModel = 0;
    }
    else if (name == CAMERA)
    {
        currentCam += moveTo;
        if (currentCam >= scene.compAmount(CAMERA))
            currentCam = 0;
    }
    else
    {
        time_t curTime = time(NULL);
        throw BadComponentName(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
}
