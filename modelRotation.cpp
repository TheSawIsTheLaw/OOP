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

    double sinAngle = sin(angle);
    double cosAngle = cos(angle);
    for (int i = 0; i < numOfNodes; i++) {
       rotateNodeZ(nodes[i].xCoord, nodes[i].yCoord,
                    xCenter, yCenter,
                    sinAngle, cosAngle);
    }
}

void yRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int xCenter, const int zCenter,
                  const float angle) {

    double sinAngle = sin(angle);
    double cosAngle = cos(angle);
    for (int i = 0; i < numOfNodes; i++) {
        rotateNodeY(nodes[i].xCoord, nodes[i].zCoord,
                    xCenter, zCenter,
                    sinAngle, cosAngle);
    }
}

void xRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int yCenter, const int zCenter,
                  const float angle) {
    double sinAngle = sin(angle);
    double cosAngle = cos(angle);
    for (int i = 0; i < numOfNodes; i++) {
        rotateNodeX(nodes[i].yCoord, nodes[i].zCoord,
                    yCenter, zCenter,
                    sinAngle, cosAngle);
        // Координаты центра принимаем
        // Функция поворота точки
        // Косинусы синусы заранее считаем
    }
}
//< End
