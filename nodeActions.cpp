#include "nodeActions.h"

#include "pointActions.h"

void rotateNodeX(double &yCoord, double &zCoord,
                 const int yCenter, const int zCenter,
                 const double sinAngle, const double cosAngle) {
    double yTemp = 0, zTemp = 0;

    yTemp = rotatePointY(yCenter, zCenter,
                       yCoord, zCoord,
                       cosAngle, -sinAngle);
    zTemp = rotatePointZ(zCenter, yCenter,
                       zCoord, yCoord,
                       cosAngle, sinAngle);

    yCoord = yTemp;
    zCoord = zTemp;
}

void rotateNodeY(double &xCoord, double &zCoord,
                 const int xCenter, const int zCenter,
                 const double sinAngle, const double cosAngle) {
    double xTemp = 0, zTemp = 0;

    xTemp = rotatePointX(xCenter, zCenter,
                       xCoord, zCoord,
                       cosAngle, sinAngle);
    zTemp = rotatePointZ(zCenter, xCenter,
                       zCoord, xCoord,
                       cosAngle, sinAngle);

    xCoord = xTemp;
    zCoord = zTemp;
}

void rotateNodeZ(double &xCoord, double &yCoord,
                 const int xCenter, const int yCenter,
                 const double sinAngle, const double cosAngle) {
    double xTemp = 0, yTemp = 0;

    xTemp = rotatePointX(xCenter, yCenter,
                       xCoord, yCoord,
                       cosAngle, sinAngle);
    yTemp = rotatePointY(yCenter, xCenter,
                       yCoord, xCoord,
                       cosAngle, sinAngle);

    xCoord = xTemp;
    yCoord = yTemp;
}
