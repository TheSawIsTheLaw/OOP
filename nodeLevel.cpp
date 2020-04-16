#include "nodeLevel.h"

#include "stdlib.h"

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

//! Copy
int copyNodesToNodes(nodeT *&nodesTo, nodeT *&nodesFrom, int numOfNodes) {
    if (!nodesFrom)
        return SUCCESS;

    if (numOfNodes <= 0)
        return INVALID_NODE_NUM_ERROR;

    if (nodesTo)
        free(nodesTo);

    nodesTo = (nodeT *)calloc(numOfNodes, sizeof(nodeT));
    if (!nodesTo)
            return MEMORY_ALLOCATION_ERROR;


    for (int i = 0; i < numOfNodes; i++) {
        nodesTo[i].xCoord = nodesFrom[i].xCoord;
        nodesTo[i].yCoord = nodesFrom[i].yCoord;
        nodesTo[i].zCoord = nodesFrom[i].zCoord;
    }

    return SUCCESS;
}
//< End

//! Scan numOfNodes
int getNumOfNodesFromFile(int &numOfNodes, FILE *modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    int gotNum;
    int read = fscanf(modelFile, "%d", &gotNum);
    if (read != 1)
        return FILE_STRUCTURE_ERROR;
    if (gotNum <= 0)
        return INVALID_NODE_NUM_ERROR;

    numOfNodes = gotNum;
    return SUCCESS;
}
//< End

//! Scan modelNodes
int scanModelNodesFromFile(nodeT *&nodes, int numOfNodes, FILE *modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    if (nodes)
        free(nodes);

    if (numOfNodes <= 0)
        return INVALID_NODE_NUM_ERROR;

    nodes = (nodeT *)calloc(numOfNodes, sizeof(nodeT));
    if (!nodes)
        return MEMORY_ALLOCATION_ERROR;

    int read;

    for (int i = 0; i < numOfNodes; i++) {
        read = fscanf(modelFile, "%lf %lf %lf",
                       &(nodes[i].xCoord),
                       &(nodes[i].yCoord),
                       &(nodes[i].zCoord));

        if (read != 3)
            return FILE_STRUCTURE_ERROR;
        if (nodes[i].xCoord < 0 || nodes[i].yCoord < 0 || nodes[i].zCoord < 0)
            return FILE_FORMAT_ERROR;
    }

    return SUCCESS;
}
//< End
