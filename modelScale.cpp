#include "modelScale.h"

#include "mainwindow.h"

#include "defines.h"

//! Wrap
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

//! Scale
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
