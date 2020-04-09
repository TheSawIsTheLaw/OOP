#ifndef MODEL_SCALE_H
#define MODEL_SCALE_H

#include "nodeLevel.h"

//! Scale
int scaleModelWrap(const int direction, nodeT *const nodes,
                   const int numOfNodes);
void scaleModel(const int direction, nodeT *const nodes,
                const int numOfNodes);
//<End

#endif // MODELSCALE_H
