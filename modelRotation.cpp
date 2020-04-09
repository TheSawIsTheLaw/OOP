#include "modelRotation.h"

#include "defines.h"

//! Wraps
int zRotateModelWrap(const int direction, nodeT *const nodes,
                     const int numOfNodes) {
    if (direction < ROTATE_Z_R || direction > ROTATE_Z_L)
        return WRONG_DIRECTION_ERROR;

    int check;
    check = areNodesLigit(nodes, numOfNodes);

    if (check)
        return check;

    zRotateModel(direction, nodes, numOfNodes);

    return SUCCESS;
}

int yRotateModelWrap(const int direction, nodeT *const nodes,
                     const int numOfNodes) {
    if (direction < ROTATE_Y_R || direction > ROTATE_Y_L)
        return WRONG_DIRECTION_ERROR;

    int check;
    check = areNodesLigit(nodes, numOfNodes);

    if (check)
        return check;

    yRotateModel(direction, nodes, numOfNodes);

    return SUCCESS;
}

int xRotateModelWrap(const int direction, nodeT *const nodes,
                     const int numOfNodes) {
    if (direction < ROTATE_X_R || direction > ROTATE_X_L)
        return WRONG_DIRECTION_ERROR;

    int check;
    check = areNodesLigit(nodes, numOfNodes);

    if (check)
        return check;

    xRotateModel(direction, nodes, numOfNodes);

    return SUCCESS;
}
//< End

//! Actions
void zRotateModel(const int direction, nodeT *const nodes,
                  const int numOfnodes) {
    double rotateAngle = PI_EIGHTEEN;
    if (direction == ROTATE_Z_R)
        rotateAngle *= REVERSED;

    double xTemp, yTemp;
    for (int i = 0; i < numOfnodes; i++) {
        xTemp = X_CENTER_SCENE +
            (nodes[i].xCoord - X_CENTER_SCENE) * cos(rotateAngle) +
            (nodes[i].yCoord - Y_CENTER_SCENE) * sin(rotateAngle);
        yTemp = Y_CENTER_SCENE -
            (nodes[i].xCoord - X_CENTER_SCENE) * sin(rotateAngle) +
            (nodes[i].yCoord - Y_CENTER_SCENE) * cos(rotateAngle);

        nodes[i].xCoord = xTemp;
        nodes[i].yCoord = yTemp;
    }
}

void yRotateModel(const int direction, nodeT *const nodes,
                  const int numOfnodes) {
    double rotateAngle = PI_EIGHTEEN;
    if (direction == ROTATE_Y_R)
        rotateAngle *= REVERSED;

    double xTemp, zTemp;
    for (int i = 0; i < numOfnodes; i++) {
        xTemp = X_CENTER_SCENE +
            (nodes[i].xCoord - X_CENTER_SCENE) * cos(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * sin(rotateAngle);
        zTemp = Z_CENTER_SCENE -
            (nodes[i].xCoord - X_CENTER_SCENE) * sin(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * cos(rotateAngle);

        nodes[i].xCoord = xTemp;
        nodes[i].zCoord = zTemp;
    }
}

void xRotateModel(const int direction, nodeT *const nodes,
                  const int numOfnodes) {
    double rotateAngle = PI_EIGHTEEN;
    if (direction == ROTATE_X_R) rotateAngle *= -1;

    double yTemp, zTemp;
    for (int i = 0; i < numOfnodes; i++) {
        yTemp = Y_CENTER_SCENE +
            (nodes[i].yCoord - Y_CENTER_SCENE) * cos(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * sin(rotateAngle);
        zTemp = Z_CENTER_SCENE -
            (nodes[i].yCoord - Y_CENTER_SCENE) * sin(rotateAngle) +
            (nodes[i].zCoord - Z_CENTER_SCENE) * cos(rotateAngle);

        nodes[i].yCoord = yTemp;
        nodes[i].zCoord = zTemp;
    }
}
//< End
