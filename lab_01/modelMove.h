#ifndef MODEL_MOVE_H
#define MODEL_MOVE_H

#include "modelDomain.h"

#include "requestActions.h"


//! Move
int moveModelWrap(modelT &model, const moveRequestT moveRequest);

void moveModelX(nodeT *const nodes, const int numOfNodes,
                const int bias);
void moveModelY(nodeT *const nodes, const int numOfNodes,
                const int bias);
//< End

#endif // MODELMOVE_H
