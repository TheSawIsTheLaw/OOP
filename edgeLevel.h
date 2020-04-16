#ifndef EDGE_LEVEL_H
#define EDGE_LEVEL_H

#include "stdio.h"

//! Edge
typedef struct {
    int firstNode;
    int secondNode;
} edgeT;
//< End

// Edge copy
int copyEdgesToEdges(edgeT *&edgesTo, edgeT *&edgesFrom, int numOfEdges);

//! Scan
int getNumOfEdgesFromFile(int &numOfEdges, FILE *modelFile);

int scanModelEdgesFromFile(edgeT *&edges, int numOfEdges, FILE *modelFile);
//< End

// Free
void freeEdges(edgeT *&edges);

#endif // EDGE_LEVEL_H
