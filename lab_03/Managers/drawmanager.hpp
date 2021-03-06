#ifndef DRAWMANAGER_H
#define DRAWMANAGER_H

#include "Drawer/drawer.hpp"
#include "managerbase.hpp"

class DrawManager : public ManagerBase
{
public:
    void drawScene(std::shared_ptr<Component> component,
                   std::shared_ptr<CameraBase> camera,
                   shared_ptr<DrawerBase> drawer);
};

#endif // DRAWMANAGER_H
