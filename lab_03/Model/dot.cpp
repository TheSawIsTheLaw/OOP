#include "dot.h"
#include "../Matrix/matrix.hpp"

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

Dot Dot::move(double dx, double dy, double dz)
{
    // clang-format off
    Matrix<4, double> moveMatrix
        = {  1,  0,  0, 0,
             0,  1,  0, 0,
             0,  0,  1, 0,
            dx, dy, dz, 1
          };
    // clang-format on
    MathVec<4, double> result = {xPosition, yPosition, zPosition};
    result.mulRight(moveMatrix);
    return Dot(result.at(0), result.at(1), result.at(2));
}

Dot Dot::scale(double coef)
{
    // clang-format off
    Matrix<4, double> scaleMatrix = { coef,    0,    0, 0,
                                         0, coef,    0, 0,
                                         0,    0, coef, 0,
                                         0,    0,    0, 1 };
    // clang-format on
}
