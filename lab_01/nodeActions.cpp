#include "nodeActions.h"

#include "pointActions.h"


//! Rotation
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
//< End

//! Move
void moveNodeX(nodeT &node, const int bias) {
    movePoint(node.xCoord, bias);
}

void moveNodeY(nodeT &node, const int bias) {
    movePoint(node.yCoord, bias);
}
//< End

//! Scale
void scaleNode(nodeT &node, const int xCenterScene,
               const int yCenterScene, const int zCenterScene,
               const float scaleCoef) {
    scalePoint(node.xCoord, xCenterScene, scaleCoef);
    scalePoint(node.yCoord, yCenterScene, scaleCoef);
    scalePoint(node.zCoord, zCenterScene, scaleCoef);
}
//< End

//! Scan
int scanNodeFromFile(nodeT &node, FILE *const modelFile) {
    int read = 0;
    if (!modelFile)
        return read;

    read += scanPointFromFile(node.xCoord, modelFile);
    read += scanPointFromFile(node.yCoord, modelFile);
    read += scanPointFromFile(node.zCoord, modelFile);

    return read;
}
//< End

//! Copy
void copyNode(nodeT &nodeTo, const nodeT nodeFrom) {
    copyPointToPoint(nodeTo.xCoord, nodeFrom.xCoord);
    copyPointToPoint(nodeTo.yCoord, nodeFrom.yCoord);
    copyPointToPoint(nodeTo.zCoord, nodeFrom.zCoord);
}
//<
