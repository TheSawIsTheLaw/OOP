#ifndef MODEL_SCALE_H
#define MODEL_SCALE_H

#include "nodeLevel.h"


//! Scale
int scaleModelWrap(nodeT *const nodes, const int direction,
                   const int numOfNodes);
void scaleModel(nodeT *const nodes, const int direction,
                const int numOfNodes);
//<End

#endif // MODELSCALE_H
