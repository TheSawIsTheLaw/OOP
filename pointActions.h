#ifndef POINT_ACTIONS_H
#define POINT_ACTIONS_H

#include "stdio.h"

//! Rotation
double rotatePointX(const double xCoord, const double secondCoord,
                    const double xCenter, const double secondCenter,
                    const double cosAngle, const double sinAngle);

double rotatePointY(const double yCoord, const double secondCoord,
                    const double yCenter, const double secondCenter,
                    const double cosAngle, const double sinAngle);

double rotatePointZ(const double zCoord, const double secondCoord,
                    const double zCenter, const double secondCenter,
                    const double cosAngle, const double sinAngle);
//< End

//! Move
void movePoint(double &point, const int bias);
//< End

//! Scale
void scalePoint(double &point, double coordCenter, const float scaleCoef);
//< End

//! Scan
int scanPointFromFile(double &point, FILE *const file);
//< End
#endif // NODEROTATION_H
