#include "edgeLevel.h"

#include "edgeActions.h"

#include "stdlib.h"

#include "defines.h"

//! Copy
int copyEdgesToEdges(edgeT *&edgesTo, const edgeT *const &edgesFrom,
                     const int numOfEdges) {
    if (!edgesFrom)
        return SUCCESS;

    if (numOfEdges < 0)
        return INVALID_EDGE_NUM_ERROR;


    edgeT *edgesTemp = (edgeT *)calloc(numOfEdges, sizeof(edgeT));
    if (!edgesTemp)
            return MEMORY_ALLOCATION_ERROR;

    if (edgesTo)
        free(edgesTo);
    edgesTo = edgesTemp;
    edgesTemp = nullptr;

    for (int i = 0; i < numOfEdges; i++)
        copyEdge(edgesTo[i], edgesFrom[i]);

    return SUCCESS;
}
//< End

//! Scan numOfEdges
int getNumOfEdgesFromFile(int &numOfEdges, FILE *const modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    int gotNum;
    int read = fscanf(modelFile, "%d", &gotNum);
    if (read != 1)
        return FILE_STRUCTURE_ERROR;
    if (gotNum < 0)
        return INVALID_EDGE_NUM_ERROR;

    numOfEdges = gotNum;
    return SUCCESS;
}
//< End

//! Scan modelEdges
int fillEdgesArrFromFile(edgeT *const &edges, const int numOfEdges,
                         FILE *const modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    if (!edges)
        return MEMORY_ALLOCATION_ERROR;

    if (numOfEdges < 0)
        return INVALID_EDGE_NUM_ERROR;

    int read = 0, check = SUCCESS;

    for (int i = 0; i < numOfEdges; i++) {
        read = scanEdgeFromFile(edges[i], modelFile);

        if (read != 2) {
            check = FILE_STRUCTURE_ERROR;
            break ;
        }
    }
    return check;
}

int scanModelEdgesFromFile(edgeT *&edges, const int numOfEdges,
                           FILE *const modelFile) {
    if (!modelFile)
        return FILE_ERROR;

    if (numOfEdges < 0)
        return INVALID_EDGE_NUM_ERROR;

    edgeT *tempEdges = (edgeT *)calloc(numOfEdges, sizeof(edgeT));
    if (!tempEdges)
        return MEMORY_ALLOCATION_ERROR;

    int check = fillEdgesArrFromFile(edges, numOfEdges, modelFile);

    if (!check) {
        if (edges)
            free(edges);
        edges = tempEdges;
        tempEdges = nullptr;
    }
    else
        free(tempEdges);

    return check;
}
//< End

//! Free edges
void freeEdges(edgeT *&edges) {
    if (edges)
        free(edges);
}
//< End
