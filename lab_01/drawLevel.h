#ifndef DRAW_LEVEL_H
#define DRAW_LEVEL_H

#include "modelDomain.h"

#include "requestActions.h"

//! Instrumnts inits
QPen initBlackPen(void);

QGraphicsScene *initScene(const int xRectStart, const int yRectStart,
                          const int xRectEnd, const int yRectEnd);

QVector<QGraphicsLineItem *> initLine(void);
//< End

//! Scene
void appendEdgeToScene(QGraphicsScene *const scene,
                       QVector<QGraphicsLineItem *> line,
                       const QPen pen,
                       nodeT *const nodes, const edgeT edge);
//< End

//! Wrap
int drawModelWrap(const modelT model, const requestT request);
//< End

#endif // DRAW_LEVEL_H
