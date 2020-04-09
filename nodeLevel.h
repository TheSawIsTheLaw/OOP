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

#endif // NODE_LEVEL_H
