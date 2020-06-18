#include "dot.hpp"
#include "../Matrix/matrix.hpp"
#include "math.h"

Dot::Dot(double xPos, double yPos, double zPos)
    : xPosition(xPos)
    , yPosition(yPos)
    , zPosition(zPos)
{
}

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

Dot Dot::move(const double dx, const double dy, const double dz) const
{
    // clang-format off
    Matrix<4, double> moveMatrix
        = {  1,  0,  0, 0,
             0,  1,  0, 0,
             0,  0,  1, 0,
            dx, dy, dz, 1
          };
    // clang-format on
    MathVec<4, double> result = { xPosition, yPosition, zPosition, 1 };
    result.mulRight(moveMatrix);
    return Dot(result.at(0), result.at(1), result.at(2));
}

Dot Dot::scale(const double coef) const
{
    // clang-format off
    Matrix<4, double> scaleMatrix = { coef,    0,    0, 0,
                                         0, coef,    0, 0,
                                         0,    0, coef, 0,
                                         0,    0,    0, 1 };
    // clang-format on
    MathVec<4, double> result = { xPosition, yPosition, zPosition, 1 };
    result.mulRight(scaleMatrix);
    return Dot(result.at(0), result.at(1), result.at(2));
}

Dot Dot::rotate(const double angle, axis ax) const
{
    Matrix<4, double> rotateMatrix;

    if (X == ax) {
        rotateMatrix.at(0, 0) = 1;
        rotateMatrix.at(2, 1) = -sin(angle);
        rotateMatrix.at(1, 1) = cos(angle);
        rotateMatrix.at(1, 2) = sin(angle);
        rotateMatrix.at(2, 2) = cos(angle);
    }
    else if (Y == ax)
    {
        rotateMatrix.at(1, 1) = 1;
        rotateMatrix.at(0, 0) = cos(angle);
        rotateMatrix.at(0, 2) = sin(angle);
        rotateMatrix.at(2, 0) = -sin(angle);
        rotateMatrix.at(2, 2) = cos(angle);
    }
    else if (Z == ax)
    {
        rotateMatrix.at(2, 2) = 1;
        rotateMatrix.at(0, 0) = cos(angle);
        rotateMatrix.at(0, 1) = sin(angle);
        rotateMatrix.at(1, 0) = -sin(angle);
        rotateMatrix.at(1, 1) = cos(angle);
    }

    MathVec<4, double> result = { xPosition, yPosition, zPosition, 1 };
    result.mulRight(rotateMatrix);
    return Dot(result.at(0), result.at(1), result.at(2));
}
