#ifndef DOT_H
#define DOT_H

class Dot
{
public:
    Dot() = default;
    Dot(double xPos, double yPos, double zPos);
    Dot(const Dot &) = default;
    ~Dot() = default;

    Dot &operator=(const Dot &) = default;

    Dot move(double dx, double dy, double dz);
    Dot rotate();
    Dot scale(double coef);

    double getXPos();
    double getYPos();
    double getZPos();

private:
    double xPosition, yPosition, zPosition;
};

#endif // DOT_H
