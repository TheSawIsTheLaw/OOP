#ifndef MODEL_ROTATION_H
#define MODEL_ROTATION_H

#include "modelDomain.h"

#pragma once
#include "requestActions.h"


// Wrap
int rotateModelWrap(modelT &model, const rotateRequestT rotateRequest);

//! Z rotate
void zRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int xCenter, const int yCenter,
                  const float angle);
//< End

//! Y rotate
void yRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int xCenter, const int zCenter,
                  const float angle);
//< End

//! X rotate
void xRotateModel(nodeT *const nodes, const int numOfNodes,
                  const int yCenter, const int zCenter,
                  const float angle);
//< End

#endif // MODELROTATION_H
