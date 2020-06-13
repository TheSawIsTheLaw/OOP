#include "drawingfactorybase.h"

QTDrawingFactory::QTDrawingFactory(QGraphicsScene *const sc) : scene(sc) {}

shared_ptr<DrawerBase> QTDrawingFactory::createDrawer()
{
    if (drawer)
        return drawer;
    drawer.reset(new QTDrawer(scene));
    return drawer;
}
