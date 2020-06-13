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
    ComponentIterator getIter(int index, ComponentName name);
    void addComponent(shared_ptr<Component> component, ComponentName name);
    void delComponent(ComponentIterator iter, ComponentName name);
    shared_ptr<Component> getComponent(int index, ComponentName name);
    int setScene(int index);

private:
    Vector<Component> components;
    int currentScene = -1;

    bool isFull(int index);
};

#endif // SCENE_H
