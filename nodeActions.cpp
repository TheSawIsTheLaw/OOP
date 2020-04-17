#include "nodeActions.h"

double rotateNodeX(const int xCenter, const int secondCenter,
                 const int xCoord, const int secondCoord,
                 const double cosAngle, const double sinAngle) {
    return xCenter +
            (xCoord - xCenter) * cosAngle +
            (secondCoord - secondCenter) * sinAngle;
}

double rotateNodeY(const int yCenter, const int secondCenter,
                 const int yCoord, const int secondCoord,
                 const double cosAngle, const double sinAngle) {
    return yCenter +
            (yCoord - yCenter) * cosAngle -
            (secondCoord - secondCenter) * sinAngle;
}

double rotateNodeZ(const int zCenter, const int secondCenter,
                 const int zCoord, const int secondCoord,
                 const double cosAngle, const double sinAngle) {
    return zCenter +
            (zCoord - zCenter) * cosAngle -
            (secondCoord - secondCenter) * sinAngle;
}
