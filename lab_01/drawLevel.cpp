#include "drawLevel.h"

#include "defines.h"

//! Instrumnts inits
QPen initBlackPen(void)
{
    static QPen blackPen(Qt::black);
    return blackPen;
}

QGraphicsScene *initScene(const int xRectStart, const int yRectStart,
                          const int xRectEnd, const int yRectEnd)
{
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(xRectStart, yRectStart, xRectEnd, yRectEnd);
    return scene;
}

QVector<QGraphicsLineItem *> initLine(void)
{
    QVector<QGraphicsLineItem *> line;
    if (line.length() != 0)
        line.clear();
    return line;
}
//< End

//! Scene
void appendEdgeToScene(QGraphicsScene *const scene,
                       QVector<QGraphicsLineItem *> line,
                       const QPen pen,
                       nodeT *const nodes, const edgeT edge)
{
    nodeT firstNode = nodes[edge.firstNode];
    nodeT secondNode = nodes[edge.secondNode];
    line.append(scene->addLine(firstNode.xCoord, firstNode.yCoord,
                               secondNode.xCoord, secondNode.yCoord, pen));
}

//! QT drawer wrap
int drawModelQtWrap(const modelT model, const drawRequestT drawRequest)
{
    int check = SUCCESS;

    if (isModelEmpty(model))
        check = MODEL_IS_EMPTY;

    if (!drawRequest.ui)
        check = UI_POINTER_ERROR;

    if (!drawRequest.scene)
        check = SCENE_ERROR;

    return check;
}
//< End

//! Wrap
int drawModelWrap(const modelT model, const requestT request)
{
    int check = drawModelQtWrap(model, request.drawRequest);

    if (!check)
        drawModel(model, request.drawRequest);

    return check;
}
//< End
