#ifndef MODEL_MOVE_H
#define MODEL_MOVE_H

#include "nodeLevel.h"

//! Move model
int moveModelWrap(const int direction, nodeT *const nodes,
                  const int numOfNodes);
void moveModel(const int direction, nodeT *const nodes,
               const int numOfNodes);
//< End

#endif // MODELMOVE_H
