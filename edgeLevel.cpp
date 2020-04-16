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
        edgesTo[i] = edgesFrom[i];
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

//! Scan modelEdges
int fillEdgesArrFromFile(edgeT *&edges, int numOfEdges, FILE *modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    if (!edges)
        return MEMORY_ALLOCATION_ERROR;

    if (numOfEdges <= 0)
        return INVALID_EDGE_NUM_ERROR;

    int read;

    for (int i = 0; i < numOfEdges; i++) {
        read = fscanf(modelFile, "%d %d",
                       &(edges[i].firstNode),
                       &(edges[i].secondNode));

        if (read != 2)
            return FILE_STRUCTURE_ERROR;
        if (edges[i].firstNode < 0 || edges[i].firstNode > numOfEdges ||
            edges[i].secondNode < 0 || edges[i].secondNode > numOfEdges )
            return FILE_FORMAT_ERROR;
    }
    return SUCCESS;
}

int scanModelEdgesFromFile(edgeT *&edges, int numOfEdges, FILE *modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    if (edges)
        free(edges);

    if (numOfEdges <= 0)
        return INVALID_EDGE_NUM_ERROR;

    edges = (edgeT *)calloc(numOfEdges, sizeof(edgeT));

    int check = fillEdgesArrFromFile(edges, numOfEdges, modelFile);

    return check;
}
//< End

//! Free edges
void freeEdges(edgeT *&edges) {
    if (edges)
        free(edges);
}
//< End
