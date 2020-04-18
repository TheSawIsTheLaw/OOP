#ifndef MODEL_SCALE_H
#define MODEL_SCALE_H

#include "modelDomain.h"

#pragma once
#include "requestActions.h"

//! Scale
int scaleModelWrap(modelT &model, const scaleRequestT scaleRequest);
void scaleModel(nodeT *const nodes, const int numOfnodes,
                const float scaleCoef, const int xCenterScene,
                const int yCenterScene, const int zCenterScene);
//<End

#endif // MODEL_SCALE_H
