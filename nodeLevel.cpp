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
int copyNodesToNodes(nodeT *&nodesTo, nodeT *const &nodesFrom,
                     const int numOfNodes) {
    if (!nodesFrom)
        return SUCCESS;

    if (numOfNodes < 0)
        return INVALID_NODE_NUM_ERROR;


    nodeT *nodesTemp = (nodeT *)calloc(numOfNodes, sizeof(nodeT));
    if (!nodesTemp)
            return MEMORY_ALLOCATION_ERROR;

    if (nodesTo)
        free(nodesTo);

    nodesTo = nodesTemp;
    nodesTemp = nullptr;

    for (int i = 0; i < numOfNodes; i++)
        copyNode(nodesTo[i], nodesFrom[i]);

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

    int check = SUCCESS;
    int read = 0;

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

    if (numOfNodes < 0)
        return INVALID_NODE_NUM_ERROR;

    nodeT *tempNodes = (nodeT *)calloc(numOfNodes, sizeof(nodeT));
    if (!tempNodes)
        return MEMORY_ALLOCATION_ERROR;

    int check = fillNodesArrFromFile(tempNodes, numOfNodes, modelFile);

    if (!check) {
        if (nodes)
            free(nodes);
        nodes = tempNodes;
        tempNodes = nullptr;
    }
    else
        free(tempNodes);

    return check;
}
//< End

//! Free
void freeNodes(nodeT *&nodes) {
    if (nodes)
        free(nodes);
}
//<
