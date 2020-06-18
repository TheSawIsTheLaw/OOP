#ifndef DRAWER_H
#define DRAWER_H

#include "../Camera/dotxy.hpp"
#include "QGraphicsScene"
#include "Vector/Vector.hpp"

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

private:
    QGraphicsScene *const grScene;
    Vector<QGraphicsLineItem *> line;
    QPen pen;
};

#endif // DRAWER_H
