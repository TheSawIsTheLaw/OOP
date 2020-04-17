#include "modelRotation.h"

#include "nodeActions.h"

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
    double sinAngle = sin(angle);
    double cosAngle = cos(angle);
    for (int i = 0; i < numOfNodes; i++) {
        xTemp = rotateNodeX(xCenter, yCenter,
                           nodes[i].xCoord, nodes[i].yCoord,
                           cosAngle, sinAngle);
        yTemp = rotateNodeY(yCenter, xCenter,
                           nodes[i].yCoord, nodes[i].xCoord,
                           cosAngle, sinAngle);

        nodes[i].xCoord = xTemp;
        nodes[i].yCoord = yTemp;
    }
}

void yRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int xCenter, const int zCenter,
                  const float angle) {
    double xTemp, zTemp;
    double sinAngle = sin(angle);
    double cosAngle = cos(angle);
    for (int i = 0; i < numOfNodes; i++) {
        xTemp = rotateNodeX(xCenter, zCenter,
                           nodes[i].xCoord, nodes[i].zCoord,
                           cosAngle, sinAngle);
        zTemp = rotateNodeZ(zCenter, xCenter,
                           nodes[i].zCoord, nodes[i].xCoord,
                           cosAngle, sinAngle);

        nodes[i].xCoord = xTemp;
        nodes[i].zCoord = zTemp;
    }
}

void xRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int yCenter, const int zCenter,
                  const float angle) {
    double yTemp, zTemp;
    double sinAngle = sin(angle);
    double cosAngle = cos(angle);
    for (int i = 0; i < numOfNodes; i++) {
        yTemp = rotateNodeY(yCenter, zCenter,
                           nodes[i].yCoord, nodes[i].zCoord,
                           cosAngle, -sinAngle);
        zTemp = rotateNodeZ(zCenter, yCenter,
                           nodes[i].zCoord, nodes[i].yCoord,
                           cosAngle, sinAngle);
        // Координаты центра принимаем
        // Функция поворота точки
        // Косинусы синусы заранее считаем

        nodes[i].yCoord = yTemp;
        nodes[i].zCoord = zTemp;
    }
}
//< End
