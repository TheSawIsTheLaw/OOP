#include "modelMove.h"

#include "defines.h"

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
//< End

//! Model move
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
//< End
