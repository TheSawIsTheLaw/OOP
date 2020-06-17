#ifndef DRAWER_H
#define DRAWER_H

#include "../Camera/dotxy.h"
#include "QGraphicsScene"

class DrawerBase
{
public:
    virtual void drawLine(const DotXY &fDot, const DotXY &sDot) = 0;
    virtual void clear() = 0;
};

class QTDrawer : public DrawerBase
{
public:
    explicit QTDrawer(QGraphicsScene *const scene);
    virtual void drawLine(const DotXY &fDot, const DotXY &sDot) override;
    virtual void clear() override;
    QGraphicsScene *getScene();

private:
    QGraphicsScene *const grScene;
};

#endif // DRAWER_H
