#include "nodeActions.h"

double rotateNodeX(const double xCenter, const double secondCenter,
                 const double xCoord, const double secondCoord,
                 const double cosAngle, const double sinAngle) {
    return xCenter +
            (xCoord - xCenter) * cosAngle +
            (secondCoord - secondCenter) * sinAngle;
}

double rotateNodeY(const double yCenter, const double secondCenter,
                 const double yCoord, const double secondCoord,
                 const double cosAngle, const double sinAngle) {
    return yCenter +
            (yCoord - yCenter) * cosAngle -
            (secondCoord - secondCenter) * sinAngle;
}

double rotateNodeZ(const double zCenter, const double secondCenter,
                 const double zCoord, const double secondCoord,
                 const double cosAngle, const double sinAngle) {
    return zCenter +
            (zCoord - zCenter) * cosAngle -
            (secondCoord - secondCenter) * sinAngle;
}
