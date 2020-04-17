#include "modelRotation.h"

#include "math.h"

#include "defines.h"


//! Wrap
int rotateModelWrap(modelT &model, const rotateRequestT rotateRequest) {
    if (areNodesLegit(model.nodes, model.numOfNodes))
        return INVALID_NODES;

    int check = SUCCESS;
    if (rotateRequest.direction == ROTATE_X)
        xRotateModel(model.nodes, model.numOfNodes,
                     rotateRequest.yCenterScene, rotateRequest.zCenterScene,
                     rotateRequest.angle);
    else if (rotateRequest.direction == ROTATE_Y)
        yRotateModel(model.nodes, model.numOfNodes,
                     rotateRequest.xCenterScene, rotateRequest.zCenterScene,
                     rotateRequest.angle);
    else if (rotateRequest.direction == ROTATE_Z)
        zRotateModel(model.nodes, model.numOfNodes,
                     rotateRequest.xCenterScene, rotateRequest.yCenterScene,
                     rotateRequest.angle);
    else
        check = INVALID_DIRECTION_ERROR;

    return check;
}

//< End

//! Actions
void zRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int xCenter, const int yCenter,
                  const float angle) {
    double xTemp, yTemp;
    for (int i = 0; i < numOfNodes; i++) {
        xTemp = xCenter +
            (nodes[i].xCoord - xCenter) * cos(angle) +
            (nodes[i].yCoord - yCenter) * sin(angle);
        yTemp = yCenter -
            (nodes[i].xCoord - xCenter) * sin(angle) +
            (nodes[i].yCoord - yCenter) * cos(angle);

        nodes[i].xCoord = xTemp;
        nodes[i].yCoord = yTemp;
    }
}

void yRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int xCenter, const int zCenter,
                  const float angle) {
    double xTemp, zTemp;
    for (int i = 0; i < numOfNodes; i++) {
        xTemp = xCenter +
            (nodes[i].xCoord - xCenter) * cos(angle) +
            (nodes[i].zCoord - zCenter) * sin(angle);
        zTemp = zCenter -
            (nodes[i].xCoord - xCenter) * sin(angle) +
            (nodes[i].zCoord - zCenter) * cos(angle);

        nodes[i].xCoord = xTemp;
        nodes[i].zCoord = zTemp;
    }
}

void xRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int yCenter, const int zCenter,
                  const float angle) {
    double yTemp, zTemp;
    for (int i = 0; i < numOfNodes; i++) {
        yTemp = yCenter +
            (nodes[i].yCoord - yCenter) * cos(angle) +
            (nodes[i].zCoord - zCenter) * sin(angle);
        zTemp = zCenter -
            (nodes[i].yCoord - yCenter) * sin(angle) +
            (nodes[i].zCoord - zCenter) * cos(angle);
        // Координаты центра принимаем
        // Функция поворота точки
        // Косинусы синусы заранее считаем

        nodes[i].yCoord = yTemp;
        nodes[i].zCoord = zTemp;
    }
}
//< End
