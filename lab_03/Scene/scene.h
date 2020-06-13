#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "../Camera/camerabase.h"
#include "../Composite/component.h"
#include "../Model/model.h"
#include "ComponentName.h"

class Scene
{
public:
    ComponentIterator getIter(size_t index, ComponentName name);
    void addComponent(shared_ptr<Component> component, ComponentName name);
    void delComponent(ComponentIterator iter, ComponentName name);
    shared_ptr<Component> getComponent(size_t index, ComponentName name);
    void setScene(size_t index);

private:
    Vector<Component> components;
    size_t currentScene = 0;

    bool isSceneFull(size_t index);
};

#endif // SCENE_H
