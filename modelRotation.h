#ifndef MODEL_ROTATION_H
#define MODEL_ROTATION_H

#include "nodeLevel.h"


//! Z rotate
int zRotateModelWrap(nodeT *const nodes, const int direction,
                     const int numOfNodes);
void zRotateModel(nodeT *const nodes, const int direction,
                  const int numOfNodes);
//< End

//! Y rotate
int yRotateModelWrap(nodeT *const nodes, const int direction,
                     const int numOfNodes);
void yRotateModel(nodeT *const nodes, const int direction,
                  const int numOfNodes);
//< End

//! X rotate
int xRotateModelWrap(nodeT *const nodes, const int direction,
                     const int numOfNodes);
void xRotateModel(nodeT *const nodes, const int direction,
                  const int numOfNodes);
//< End

#endif // MODELROTATION_H
