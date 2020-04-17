#ifndef NODE_ACTIONS_H
#define NODE_ACTIONS_H

#include "nodeLevel.h"

//! Rotation
void rotateNodeX(nodeT &node,
                 const int yCenter, const int zCenter,
                 const double sinAngle, const double cosAngle);

void rotateNodeY(nodeT &node,
                 const int xCenter, const int zCenter,
                 const double sinAngle, const double cosAngle);

void rotateNodeZ(nodeT &node,
                 const int xCenter, const int yCenter,
                 const double sinAngle, const double cosAngle);
//< End

//! Move
void moveNodeX(nodeT &node, const int bias);

void moveNodeY(nodeT &node, const int bias);
//< End

//! Scale
void scaleNode(nodeT &node, const int xCenterScene,
               const int yCenterScene, const int zCenterScene,
               const float scaleCoef);
//< End

//! Scan
int scanNodeFromFile(nodeT &node, FILE *const modelFile);
//< End

#endif // NODE_ACTIONS_H
