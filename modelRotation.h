#ifndef MODEL_ROTATION_H
#define MODEL_ROTATION_H

#include "nodeLevel.h"

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

#endif // MODELROTATION_H
