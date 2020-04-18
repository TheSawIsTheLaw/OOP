#ifndef DRAW_LEVEL_H
#define DRAW_LEVEL_H

#include "modelDomain.h"

#include "requestActions.h"

int drawModelWrap(modelT model, requestT request);

QPen initBlackPen(void);

#endif // DRAW_LEVEL_H
