#ifndef EDGE_LEVEL_H
#define EDGE_LEVEL_H

#include "stdio.h"

//! Edge
typedef struct {
    int firstNode;
    int secondNode;
} edgeT;
//< End

//! Edge copy
int copyEdgesToEdges(edgeT *&edgesTo, const edgeT * const &edgesFrom,
                     const int numOfEdges);
//< End

//! Scan
int getNumOfEdgesFromFile(int &numOfEdges, FILE * const modelFile);

int scanModelEdgesFromFile(edgeT *&edges, const int numOfEdges,
                           FILE * const modelFile);
//< End

//! Free
void freeEdges(edgeT *&edges);
//< End

#endif // EDGE_LEVEL_H
