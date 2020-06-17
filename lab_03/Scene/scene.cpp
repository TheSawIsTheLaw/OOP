#include "scene.h"
#include "time.h"

void Scene::addComponent(shared_ptr<Component> component, ComponentName name)
{
    if (name == SCENE && component->isComposite())
    {
        qDebug("Yep, it's composite");
        components.push_back(component);
        currentScene++;
    }
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

bool Scene::isFull(int index)
{
    bool hasCam = false;
    bool hasMod = false;
    auto curScene = components[index];

    for (auto iter = curScene->begin(); iter != curScene->end() && !(hasCam && hasMod); iter++) {
        if ((*iter)->isVisible())
            hasMod = true;
        else if (!(*iter)->isComposite())
            hasCam = true;
    }

    return hasCam && hasMod;
}

ComponentIterator Scene::getIter(int index, ComponentName name)
{
    qDebug("CurScene: %d; curComponentsSize:%zu \n", currentScene, components.size());
    if (currentScene < 0 || currentScene >= static_cast<int>(components.size())) {
        time_t curTime = time(NULL);
        throw InvalidCurrentSceneNum(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (name == SCENE)
        return components.begin() + currentScene;

    Composite &composite = dynamic_cast<Composite &>(*components[currentScene]);

    if (name == MODEL)
    {
        int i = -1;
        auto iter = composite.begin();
        while (iter != composite.end() && i != index)
        {
            if ((*iter)->isVisible())
                i++;
            if (index == i)
                return iter;
            iter++;
        }
    }
    else if (name == CAMERA)
    {
        int i = -1;
        auto iter = composite.begin();
        while (iter != composite.end() && i != index)
        {
            if (!(*iter)->isVisible())
                i++;
            if (index == i)
                return iter;
            iter++;
        }
    }
    time_t curTime = time(NULL);
    throw InvalidComponentIndex(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
}

shared_ptr<Component> Scene::getComponent(int index, ComponentName name)
{
    ComponentIterator iter = getIter(index, name);
    return *iter;
}

int Scene::setScene(int index)
{
    if (index >= 0)
        currentScene = index;
    else
        currentScene = 0;
    return currentScene;
}
