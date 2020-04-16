#ifndef NODE_LEVEL_H
#define NODE_LEVEL_H


//! Node
typedef struct {
    double xCoord;
    double yCoord;
    double zCoord;
} nodeT;
//< End

//! Check
int areNodesLigit(const nodeT *const nodes, const int numOfNodes);
//< End

// Copy
int copyNodesToNodes(nodeT *&nodesTo, nodeT *&nodesFrom, int numOfNodes);

#endif // NODE_LEVEL_H
