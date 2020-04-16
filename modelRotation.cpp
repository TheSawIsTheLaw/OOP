#include "modelRotation.h"

#include "math.h"

#include "defines.h"


//! Wrap
int rotateModelWrap(modelT &model, rotateRequestT rotateRequest) {
    if (areNodesLegit(model.nodes, model.numOfNodes))
        return INVALID_NODES;

    int check = SUCCESS;
    if (rotateRequest.direction == ROTATE_X)
        xRotateModel(model.nodes, rotateRequest.angle, model.numOfNodes);
    else if (rotateRequest.direction == ROTATE_Y)
        yRotateModel(model.nodes, rotateRequest.angle, model.numOfNodes);
    else if (rotateRequest.direction == ROTATE_Z)
        zRotateModel(model.nodes, rotateRequest.angle, model.numOfNodes);
    else
        check = WRONG_DIRECTION_ERROR;

    return check;
}

//< End

//! Actions
void zRotateModel(nodeT *const nodes, const float angle,
                  const int numOfnodes) {
    double xTemp, yTemp;
    for (int i = 0; i < numOfnodes; i++) {
        xTemp = X_CENTER_SCENE +
            (nodes[i].xCoord - X_CENTER_SCENE) * cos(angle) +
            (nodes[i].yCoord - Y_CENTER_SCENE) * sin(angle);
        yTemp = Y_CENTER_SCENE -
            (nodes[i].xCoord - X_CENTER_SCENE) * sin(angle) +
            (nodes[i].yCoord - Y_CENTER_SCENE) * cos(angle);

        nodes[i].xCoord = xTemp;
        nodes[i].yCoord = yTemp;
    }
}

void yRotateModel(nodeT *const nodes, const float angle,
                  const int numOfnodes) {
    double xTemp, zTemp;
    for (int i = 0; i < numOfnodes; i++) {
        xTemp = X_CENTER_SCENE +
            (nodes[i].xCoord - X_CENTER_SCENE) * cos(angle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * sin(angle);
        zTemp = Z_CENTER_SCENE -
            (nodes[i].xCoord - X_CENTER_SCENE) * sin(angle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * cos(angle);

        nodes[i].xCoord = xTemp;
        nodes[i].zCoord = zTemp;
    }
}

void xRotateModel(nodeT *const nodes, const float angle,
                  const int numOfnodes) {
    double yTemp, zTemp;
    for (int i = 0; i < numOfnodes; i++) {
        yTemp = Y_CENTER_SCENE +
            (nodes[i].yCoord - Y_CENTER_SCENE) * cos(angle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * sin(angle);
        zTemp = Z_CENTER_SCENE -
            (nodes[i].yCoord - Y_CENTER_SCENE) * sin(angle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * cos(angle);

        nodes[i].yCoord = yTemp;
        nodes[i].zCoord = zTemp;
    }
}
//< End
