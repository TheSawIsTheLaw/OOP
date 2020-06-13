#include "scene.h"
#include "time.h"

void Scene::addComponent(shared_ptr<Component> component, ComponentName name)
{
    if (name == SCENE && component->isComposite())
        components.push_back(component);
    else if (!component->isComposite())
        components[currentScene]->add(component);
    else {
        time_t curTime = time(NULL);
        throw InvalidComponentName(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
}

void Scene::delComponent(ComponentIterator iter, ComponentName name)
{
    if (name == SCENE)
        components.erase(iter);
    else
        components[currentScene]->del(iter);
}

bool Scene::isFull(size_t index)
{
    bool hasCam = false;
    bool hasMod = false;
    auto curScene = components[index];

    for (auto iter = curScene->begin(); iter != curScene->end() && !(hasCam && hasMod); iter++) {
        if ((*iter).isVisible())
            hasMod = true;
        else if (!(*iter)->isComposite())
            hasCam = true;
    }

    return hasCam && hasMod;
}
