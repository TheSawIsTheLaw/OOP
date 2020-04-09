#ifndef NODE_LEVEL_H
#define NODE_LEVEL_H

//! Node
typedef struct {
    double xCoord;
    double yCoord;
    double zCoord;
} nodeT;
//< End

//! Move model
int moveModelWrap(const int direction, nodeT *const nodes,
                  const int numOfNodes);
void moveModel(const int direction, nodeT *const nodes,
               const int numOfNodes);
//< End

//! Z rotate
int zRotateModelWrap(const int direction, nodeT *const nodes,
                     const int numOfNodes);
void zRotateModel(const int direction, nodeT *const nodes,
                  const int numOfNodes);
//< End

//! Y rotate
int yRotateModelWrap(const int direction, nodeT *nodes,
                     const int numOfNodes);
void yRotateModel(const int direction, nodeT *const nodes,
                  const int numOfNodes);
//< End

//! X rotate
int xRotateModelWrap(const int direction, nodeT *const nodes,
                     const int numOfNodes);
void xRotateModel(const int direction, nodeT *const nodes,
                  const int numOfNodes);
//< End

//! Scale
int scaleModelWrap(const int direction, nodeT *const nodes,
                   const int numOfNodes);
void scaleModel(const int direction, nodeT *const nodes,
                const int numOfNodes);
//<End

//! Check
int areNodesLigit(const nodeT *const nodes, const int numOfNodes);
//< End

#endif // NODE_LEVEL_H
