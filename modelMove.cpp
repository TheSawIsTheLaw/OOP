#include "modelMove.h"

#include "defines.h"

//! Wraps
int moveModelWrap(modelT &model, moveRequestT moveRequest) {
    if (moveRequest.direction != GO_X && moveRequest.direction != GO_Y)
        return WRONG_DIRECTION_ERROR;

    if (areNodesLegit(model.nodes, model.numOfNodes))
            return INVALID_NODES;

    if (moveRequest.direction == GO_X)
        moveModelX(model.nodes, moveRequest.bias,
                   model.numOfNodes);
    else
        moveModelY(model.nodes, moveRequest.bias,
                   model.numOfNodes);

    return SUCCESS;
}
//< End

//! Model move
void moveModelX(nodeT *const nodes, const int bias,
                const int numOfNodes) {
    for (int i = 0; i < numOfNodes; i++)
        nodes[i].xCoord += bias;
}

void moveModelY(nodeT *const nodes, const int bias,
                const int numOfNodes) {
    for (int i = 0; i < numOfNodes; i++)
        nodes[i].yCoord += bias;
}
//< End
