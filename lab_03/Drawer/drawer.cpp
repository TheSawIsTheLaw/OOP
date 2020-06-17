#include "drawer.h"

QTDrawer::QTDrawer(QGraphicsScene *const scene)
    : grScene(scene)
{
    QVector<QGraphicsLineItem *> line;
    if (line.length() != 0)
        line.clear();
    QPen blackPen(Qt::black);
}

void QTDrawer::drawLine(const DotXY &fDot, const DotXY &sDot)
{
    line.append(grScene->addLine(fDot.getXCoordinate(),
                                 fDot.getYCoordinate(),
                                 sDot.getXCoordinate(),
                                 sDot.getYCoordinate(), blackPen));
}

void QTDrawer::clear()
{
    grScene->clear();
}

QGraphicsScene *QTDrawer::getScene()
{
    return grScene;
}
