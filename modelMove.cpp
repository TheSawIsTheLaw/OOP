#include "modelMove.h"

#include "nodeActions.h"

#include "defines.h"

//! Wraps
int moveModelWrap(modelT &model, const moveRequestT moveRequest) {
    if (areNodesLegit(model.nodes, model.numOfNodes))
            return INVALID_NODES;

    int check = SUCCESS;
    if (moveRequest.direction == GO_X)
        moveModelX(model.nodes, model.numOfNodes,
                   moveRequest.bias);
    else if (moveRequest.direction == GO_Y)
        moveModelY(model.nodes, model.numOfNodes,
                   moveRequest.bias);
    else
        check = INVALID_DIRECTION_ERROR;

    return check;
}
//< End

//! Model move
void moveModelX(nodeT *const nodes, const int numOfNodes,
                const int bias) {
    for (int i = 0; i < numOfNodes; i++)
        moveNodeX(nodes[i], bias);
}

void moveModelY(nodeT *const nodes, const int numOfNodes,
                const int bias) {
    for (int i = 0; i < numOfNodes; i++)
        moveNodeY(nodes[i], bias);
}
//< End
