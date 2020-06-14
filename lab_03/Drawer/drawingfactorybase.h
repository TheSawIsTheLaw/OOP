#ifndef DRAWINGFACTORYBASE_H
#define DRAWINGFACTORYBASE_H

#include "drawer.h"
#include <memory>

class DrawingFactoryBase
{
public:
    virtual std::shared_ptr<DrawerBase> createDrawer() = 0;
};

class QTDrawingFactory : public DrawingFactoryBase
{
public:
    explicit QTDrawingFactory(QGraphicsScene *const scene);
    virtual std::shared_ptr<DrawerBase> createDrawer() override;

private:
    QGraphicsScene *const scene;
    std::shared_ptr<DrawerBase> drawer;
};

#endif // DRAWINGFACTORYBASE_H
