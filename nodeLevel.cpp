#include "nodeLevel.h"

#include "nodeActions.h"

#include "stdlib.h"

#include "defines.h"


//! Check
int areNodesLegit(const nodeT *const nodes, const int numOfNodes) {
    if (!nodes)
        return INVALID_NODES;

    if (numOfNodes < EMPTY)
        return INVALID_NODE_NUM_ERROR;

    return SUCCESS;
}
//< End

//! Copy
int copyNodesToNodes(nodeT *&nodesTo, nodeT *const &nodesFrom, const int numOfNodes) {
    if (!nodesFrom)
        return SUCCESS;

    if (numOfNodes < 0)
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
int getNumOfNodesFromFile(int &numOfNodes, FILE *const modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    int gotNum;
    int read = fscanf(modelFile, "%d", &gotNum);
    if (read != 1)
        return FILE_STRUCTURE_ERROR;
    if (gotNum < 0)
        return INVALID_NODE_NUM_ERROR;

    numOfNodes = gotNum;
    return SUCCESS;
}
//< End

//! Scan modelNodes
int fillNodesArrFromFile(nodeT *&nodes, int numOfNodes,
                         FILE *const modelFile) {
    if (!modelFile)
        return FILE_ERROR;
    if (!nodes)
        return MEMORY_ALLOCATION_ERROR;

    if (numOfNodes < 0)
        return INVALID_NODE_NUM_ERROR;

    int read = 0, check = SUCCESS;

    for (int i = 0; i < numOfNodes; i++) {
        read = scanNodeFromFile(nodes[i], modelFile);// FIXED вынесено на новый уровень

        if (read != 3) {
            check = FILE_STRUCTURE_ERROR;
            break ;
        } // FIXED Грязь
    }
    return check;
}

int scanModelNodesFromFile(nodeT *&nodes, const int numOfNodes,
                           FILE *const modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    if (nodes)
        free(nodes);

    if (numOfNodes < 0)
        return INVALID_NODE_NUM_ERROR;

    nodes = (nodeT *)calloc(numOfNodes, sizeof(nodeT));

    int check = fillNodesArrFromFile(nodes, numOfNodes, modelFile);
    // НЕ ОТРАБОТАЛА - ОСВОБОДИЛИ

    if (check)
        free(nodes);

    return check;
}
//< End

//! Free
void freeNodes(nodeT *&nodes) {
    if (nodes)
        free(nodes);
}
//<
