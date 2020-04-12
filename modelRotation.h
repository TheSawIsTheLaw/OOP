#ifndef MODEL_ROTATION_H
#define MODEL_ROTATION_H

#include "modelDomain.h"

#include "requestActions.h"


// Wrap
int rotateModelWrap(modelT &model, rotateRequestT rotateRequest);

//! Z rotate
void zRotateModel(nodeT *const nodes, const float angle,
                  const int numOfNodes);
//< End

//! Y rotate
void yRotateModel(nodeT *const nodes, const float angle,
                  const int numOfNodes);
//< End

//! X rotate
void xRotateModel(nodeT *const nodes, const float angle,
                  const int numOfNodes);
//< End

#endif // MODELROTATION_H
