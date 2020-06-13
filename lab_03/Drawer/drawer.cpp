#include "drawer.h"

QTDrawer::QTDrawer(QGraphicsScene *scene) : grScene(scene) {}

void QTDrawer::drawLine(const DotXY &fDot, const DotXY &sDot)
{
    grScene->addLine(fDot.getXCoordinate(),
                     fDot.getYCoordinate(),
                     sDot.getXCoordinate(),
                     sDot.getYCoordinate());
}
