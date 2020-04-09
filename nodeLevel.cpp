#include "mainwindow.h"

#include "nodeLevel.h"

#include "modelMove.h"

#include "defines.h"

//! Check
int areNodesLigit(const nodeT *const nodes, const int numOfNodes) {
    if (!nodes)
        return INVALID_NODES_MOVE_POINTER_ERROR;

    if (numOfNodes <= EMPTY)
        return WRONG_NUMBER_OF_NODES_ERROR;

    return SUCCESS;
}
//< End
