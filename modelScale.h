#ifndef MODEL_SCALE_H
#define MODEL_SCALE_H

#include "modelDomain.h"

#include "requestActions.h"


//! Scale
int scaleModelWrap(modelT &model, scaleRequestT scaleRequest);
void scaleModel(nodeT *const nodes, const float scaleCoef,
                const int xCenterScene, const int yCenterScene,
                const int zCenterScene, const int numOfnodes);
//<End

#endif // MODELSCALE_H
