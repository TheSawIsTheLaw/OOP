#include "edgeLevel.h"

#include "stdlib.h"

#include "defines.h"

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
