#include "nodeActions.h"

#include "pointActions.h"

void rotateNodeX(nodeT &node,
                 const int yCenter, const int zCenter,
                 const double sinAngle, const double cosAngle) {
    double yTemp = 0, zTemp = 0;

    yTemp = rotatePointY(node.yCoord, node.zCoord,
                         yCenter, zCenter,
                         cosAngle, -sinAngle);
    zTemp = rotatePointZ(node.zCoord, node.yCoord,
                         zCenter, yCenter,
                         cosAngle, sinAngle);

    node.yCoord = yTemp;
    node.zCoord = zTemp;
}

void rotateNodeY(nodeT &node,
                 const int xCenter, const int zCenter,
                 const double sinAngle, const double cosAngle) {
    double xTemp = 0, zTemp = 0;

    xTemp = rotatePointX(node.xCoord, node.zCoord,
                         xCenter, zCenter,
                         cosAngle, sinAngle);
    zTemp = rotatePointZ(node.zCoord, node.xCoord,
                         zCenter, xCenter,
                         cosAngle, sinAngle);

    node.xCoord = xTemp;
    node.zCoord = zTemp;
}

void rotateNodeZ(nodeT &node,
                 const int xCenter, const int yCenter,
                 const double sinAngle, const double cosAngle) {
    double xTemp = 0, yTemp = 0;

    xTemp = rotatePointX(node.xCoord, node.yCoord,
                        xCenter, yCenter,
                        cosAngle, sinAngle);
    yTemp = rotatePointY(node.yCoord, node.xCoord,
                         yCenter, xCenter,
                         cosAngle, sinAngle);

    node.xCoord = xTemp;
    node.yCoord = yTemp;
}
