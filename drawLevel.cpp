#include "drawLevel.h"

#include "defines.h"

QPen initBlackPen(void) {
    static QPen blackPen(Qt::black);
    return blackPen;
}

QGraphicsScene *initScene(const int xRectStart, const int yRectStart,
                          const int xRectEnd, const int yRectEnd) {
    QGraphicsScene *scene = new QGraphicsScene(Q_NULLPTR);
    scene->setSceneRect(xRectStart, yRectStart, xRectEnd, yRectEnd);
    return scene;
}

QVector<QGraphicsLineItem *> initLine(void) {
    QVector<QGraphicsLineItem *> line;
    if (line.length() != 0)
        line.clear();
    return line;
}


void appendNodeToLine(QVector<QGraphicsLineItem *> line,
                      QGraphicsScene *scene,
                      QPen pen, nodeT firstNode,
                      nodeT secondNode) {
    line.append(scene->addLine(firstNode.xCoord, firstNode.yCoord,
        secondNode.xCoord, secondNode.yCoord, pen));
}

void appendEdgeToLine(QVector<QGraphicsLineItem *> line,
                   QGraphicsScene *scene,
                   QPen pen, nodeT *nodes,
                   edgeT edge) {
    nodeT firstNode = nodes[edge.firstNode];
    nodeT secondNode = nodes[edge.secondNode];
    appendNodeToLine(line, scene, pen, firstNode, secondNode);
}

int drawModelQtWrap(modelT model, drawRequestT drawRequest) {
    if (isModelEmpty(model))
        return MODEL_IS_EMPTY;

    if (!drawRequest.ui)
        return UI_POINTER_ERROR;

    drawModelQt(model, drawRequest.xRectStart,
                drawRequest.yRectStart, drawRequest.xRectEnd,
                drawRequest.yRectEnd, drawRequest.ui);

    return SUCCESS;
}

int drawModelWrap(modelT model, requestT request) {
    if (isModelEmpty(model))
        return MODEL_IS_EMPTY;

    int check = drawModelQtWrap(model, request.drawRequest);

    return check;
}

