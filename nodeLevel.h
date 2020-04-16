#ifndef NODE_LEVEL_H
#define NODE_LEVEL_H

#include "stdio.h"


//! Node
typedef struct {
    double xCoord;
    double yCoord;
    double zCoord;
} nodeT;
//< End

//! Check
int areNodesLegit(const nodeT *const nodes, const int numOfNodes);
//< End

//! Copy
int copyNodesToNodes(nodeT *&nodesTo, nodeT *&nodesFrom, int numOfNodes);
//< End

//! Scan
int getNumOfNodesFromFile(int &numOfNodes, FILE *modelFile);

int scanModelNodesFromFile(nodeT *&nodes, int numOfNodes, FILE *modelFile);
//< End

// Free
void freeNodes(nodeT *&nodes);

#endif // NODE_LEVEL_H
