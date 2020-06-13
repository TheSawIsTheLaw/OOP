#ifndef DOT_H
#define DOT_H

#include "defines.h"

class Dot
{
public:
    Dot() = default;
    Dot(double xPos, double yPos, double zPos);
    Dot(const Dot &) = default;
    ~Dot() = default;

    Dot &operator=(const Dot &) = default;

    Dot move(const double dx, const double dy, const double dz) const;
    Dot rotate(const double angle, axis ax) const;
    Dot scale(const double coef) const;

    double getXPos();
    double getYPos();
    double getZPos();

private:
    double xPosition, yPosition, zPosition;
};

#endif // DOT_H
