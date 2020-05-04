#include "pointActions.h"


//! Rotation
double rotatePointX(const double xCoord, const double secondCoord,
                    const double xCenter, const double secondCenter,
                    const double cosAngle, const double sinAngle) {
    return xCenter +
            (xCoord - xCenter) * cosAngle +
            (secondCoord - secondCenter) * sinAngle;
}

double rotatePointY(const double yCoord, const double secondCoord,
                    const double yCenter, const double secondCenter,
                    const double cosAngle, const double sinAngle) {
    return yCenter +
            (yCoord - yCenter) * cosAngle -
            (secondCoord - secondCenter) * sinAngle;
}

double rotatePointZ(const double zCoord, const double secondCoord,
                    const double zCenter, const double secondCenter,
                    const double cosAngle, const double sinAngle) {
    return zCenter +
            (zCoord - zCenter) * cosAngle -
            (secondCoord - secondCenter) * sinAngle;
}
//< End

//! Move
void movePoint(double &point, const int bias) {
    point += bias;
}
//< End

//! Scale
void scalePoint(double &point, const double coordCenter,
                const float scaleCoef) {
    point = point * scaleCoef + (1 - scaleCoef) * coordCenter;
}
//< End

//! Scan
int scanPointFromFile(double &point, FILE *const file) {
    int read = 0;
    if (!file)
        return read;

    read = fscanf(file, "%lf", &point);
    return read;
}

int scanPointSerNumFromFile(int &serNum, FILE *const file) {
    int read = 0;
    if (!file)
        return read;

    read = fscanf(file, "%d", &serNum);
    return read;
}
//< End

//! Copy
void copyPointToPoint(double &pointTo, const double pointFrom) {
    pointTo = pointFrom;
}
//< End
