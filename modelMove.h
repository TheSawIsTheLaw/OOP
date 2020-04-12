#ifndef MODEL_MOVE_H
#define MODEL_MOVE_H

#include "modelDomain.h"

#include "requestActions.h"


//! Move
int moveModelWrap(modelT &model, moveRequestT moveRequest);

void moveModelX(nodeT *const nodes, const int bias,
                const int numOfNodes);
void moveModelY(nodeT *const nodes, const int bias,
                const int numOfNodes);
//< End

#endif // MODELMOVE_H
