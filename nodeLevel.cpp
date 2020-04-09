#include "mainwindow.h"

#include "nodeLevel.h"

#include "defines.h"

//! Check
int areNodesLigit(const nodeT *const nodes, const int numOfNodes) {
    if (!nodes)
        return INVALID_NODES_MOVE_POINTER_ERROR;

    if (numOfNodes <= EMPTY)
        return WRONG_NUMBER_OF_NODES_ERROR;

    return SUCCESS;
}
//> End

//! Wraps
int moveModelWrap(const int direction, nodeT *const nodes,
                  const int numOfNodes) {
    if (direction < GO_LEFT || direction > GO_RIGHT)
        return WRONG_DIRECTION_ERROR;

    int check;
    check = areNodesLigit(nodes, numOfNodes);

    if (check)
        return check;

    moveModel(direction, nodes, numOfNodes);

    return SUCCESS;
}

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

int scaleModelWrap(const int direction, nodeT *const nodes,
                   const int numOfNodes) {
    if (direction < SCALE_PLUS || direction > SCALE_MINUS)
        return WRONG_DIRECTION_ERROR;

    int check;
    check = areNodesLigit(nodes, numOfNodes);

    if (check)
        return check;

    scaleModel(direction, nodes, numOfNodes);

    return SUCCESS;
}
//< End

//! Actions
void moveModel(const int direction, nodeT *const nodes,
               const int numOfNodes) {
    int moveDirection;
    if (direction == GO_LEFT || direction == GO_RIGHT) {
        if (direction == GO_RIGHT)
            moveDirection = MOVE_UNIT;
        else
            moveDirection = -MOVE_UNIT;
        for (int i = 0; i < numOfNodes; i++)
            nodes[i].xCoord += moveDirection;
    }
    else if (direction == GO_UP || direction == GO_DOWN) {
        if (direction == GO_UP)
            moveDirection = -MOVE_UNIT;
        else
            moveDirection = MOVE_UNIT;
        for (int i = 0; i < numOfNodes; i++)
            nodes[i].yCoord += moveDirection;
    }
}

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

void scaleModel(const int direction, nodeT *const nodes,
                const int numOfnodes) {
    double scaleCoef = SCALE_UNIT_MINUS;
    if (direction == SCALE_PLUS)
        scaleCoef = SCALE_UNIT_PLUS;

    qDebug("scale");

    for (int i = 0; i < numOfnodes; i++) {
        nodes[i].xCoord =
            nodes[i].xCoord * scaleCoef + (1 - scaleCoef) * X_CENTER_SCENE;
        nodes[i].yCoord =
            nodes[i].yCoord * scaleCoef + (1 - scaleCoef) * Y_CENTER_SCENE;
        nodes[i].zCoord =
            nodes[i].zCoord * scaleCoef + (1 - scaleCoef) * Z_CENTER_SCENE;
    }
}
// End
