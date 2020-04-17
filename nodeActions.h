#ifndef NODE_ACTIONS_H
#define NODE_ACTIONS_H

#include "nodeLevel.h"

void rotateNodeX(nodeT &node,
                 const int yCenter, const int zCenter,
                 const double sinAngle, const double cosAngle);

void rotateNodeY(nodeT &node,
                 const int xCenter, const int zCenter,
                 const double sinAngle, const double cosAngle);

void rotateNodeZ(nodeT &node,
                 const int xCenter, const int yCenter,
                 const double sinAngle, const double cosAngle);

void moveNodeX();

#endif // NODEACTIONS_H
