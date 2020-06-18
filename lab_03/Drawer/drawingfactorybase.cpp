#include "drawingfactorybase.h"

QTDrawingFactory::QTDrawingFactory(QGraphicsScene *const sc)
    : drawer(new QTDrawer(sc))
{
}

std::shared_ptr<DrawerBase> QTDrawingFactory::createDrawer()
{
    return drawer;
}
