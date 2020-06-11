#include "dot.h"

Dot::Dot(double xPos, double yPos, double zPos) : xPosition(xPos), yPosition(yPos), zPosition(zPos)
{}

double Dot::getXPos()
{
    return xPosition;
}

double Dot::getYPos()
{
    return yPosition;
}

double Dot::getZPos()
{
    return zPosition;
}
