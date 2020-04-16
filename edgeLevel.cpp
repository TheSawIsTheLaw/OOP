#include "edgeLevel.h"

#include "stdlib.h"

#include "defines.h"

//! Copy
int copyEdgesToEdges(edgeT *&edgesTo, edgeT *&edgesFrom, int numOfEdges) {
    if (!edgesFrom)
        return SUCCESS;

    if (numOfEdges < 0)
        return INVALID_EDGE_NUM_ERROR;

    if (edgesTo)
        free(edgesTo);

    edgesTo = (edgeT *)calloc(numOfEdges, sizeof(edgeT));
    if (!edgesTo)
            return MEMORY_ALLOCATION_ERROR;


    for (int i = 0; i < numOfEdges; i++) {
        edgesTo[i].firstNode = edgesFrom[i].firstNode;
        edgesTo[i].secondNode = edgesFrom[i].secondNode;
    }
    return SUCCESS;
}
//< End

//! Scan numOfEdges
int getNumOfEdgesFromFile(int &numOfEdges, FILE *modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    int gotNum;
    int read = fscanf(modelFile, "%d", &gotNum);
    if (read != 1)
        return FILE_STRUCTURE_ERROR;
    if (gotNum <= 0)
        return INVALID_NODE_NUM_ERROR;

    numOfEdges = gotNum;
    return SUCCESS;
}
//< End
//< End
