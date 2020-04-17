#ifndef NODE_ACTIONS_H
#define NODE_ACTIONS_H

//! Node rotation
double rotateNodeX(const int xCenter, const int secondCenter,
                 const int xCoord, const int secondCoord,
                 const double cosAngle, const double sinAngle);

double rotateNodeY(const int yCenter, const int secondCenter,
                 const int yCoord, const int secondCoord,
                 const double cosAngle, const double sinAngle);

double rotateNodeZ(const int zCenter, const int secondCenter,
                 const int zCoord, const int secondCoord,
                 const double cosAngle, const double sinAngle);
//< End

#endif // NODEROTATION_H
