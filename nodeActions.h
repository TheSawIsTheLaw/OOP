#ifndef NODE_ACTIONS_H
#define NODE_ACTIONS_H

#include "nodeLevel.h"

void rotateNodeX(double &yCoord, double &zCoord,
                 const int yCenter, const int zCenter,
                 const double sinAngle, const double cosAngle);

void rotateNodeY(double &xCoord, double &zCoord,
                 const int xCenter, const int zCenter,
                 const double sinAngle, const double cosAngle);

void rotateNodeZ(double &xCoord, double &yCoord,
                 const int xCenter, const int yCenter,
                 const double sinAngle, const double cosAngle);

#endif // NODEACTIONS_H
