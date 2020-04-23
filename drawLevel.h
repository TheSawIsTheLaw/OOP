#ifndef DRAW_LEVEL_H
#define DRAW_LEVEL_H

#include "modelDomain.h"

#include "requestActions.h"

int drawModelWrap(const modelT model, const requestT request);

QPen initBlackPen(void);

QGraphicsScene *initScene(const int xRectStart, const int yRectStart,
                          const int xRectEnd, const int yRectEnd);

QVector<QGraphicsLineItem *> initLine(void);

void appendEdgeToScene(QGraphicsScene *const scene,
                       QVector<QGraphicsLineItem *> line,
                       const QPen pen,
                       nodeT *const nodes, const edgeT edge);


#endif // DRAW_LEVEL_H
