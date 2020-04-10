#ifndef MODEL_MOVE_H
#define MODEL_MOVE_H

#include "nodeLevel.h"


//! Move
int moveModelWrap(nodeT *const nodes, const int direction,
                  const int numOfNodes);
void moveModel(nodeT *const nodes, const int direction,
               const int numOfNodes);
//< End

#endif // MODELMOVE_H
