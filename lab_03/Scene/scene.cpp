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
