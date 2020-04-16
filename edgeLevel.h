#ifndef EDGE_LEVEL_H
#define EDGE_LEVEL_H


//! Edge
typedef struct {
    int firstNode;
    int secondNode;
} edgeT;
//< End

// Edge copy
int copyEdgesToEdges(edgeT *&edgesTo, edgeT *&edgesFrom, int numOfEdges);

#endif // EDGE_LEVEL_H
