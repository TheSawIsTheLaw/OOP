#include "modelMove.h"

#include "defines.h"

//! Wraps
int moveModelWrap(modelT &model, moveRequestT moveRequest) {
    if (moveRequest.direction != GO_X && moveRequest.direction != GO_Y)
        return WRONG_DIRECTION_ERROR;

    int check;
    check = areNodesLigit(model.nodes, model.numOfNodes);

    if (check == SUCCESS) {
        if (moveRequest.direction == GO_X)
            moveModelX(model.nodes, moveRequest.bias,
                       model.numOfNodes);
        else
            moveModelY(model.nodes, moveRequest.bias,
                       model.numOfNodes);
    }

    return check;
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
