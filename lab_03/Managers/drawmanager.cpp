#include "drawmanager.h"

QGraphicsScene *DrawManager::drawScene(std::shared_ptr<Component> component,
                                       std::shared_ptr<CameraBase> camera,
                                       shared_ptr<DrawerBase> drawer)
{
    std::shared_ptr<ComponentVisitorBase> drawVisitor(new DrawVisitor(drawer, camera));
    component->accept(*drawVisitor);
    return dynamic_cast<QTDrawer *>(drawer.get())->getScene();
}
