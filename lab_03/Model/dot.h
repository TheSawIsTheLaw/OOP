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

    void move();
    void rotate();
    void scale();

    double getXPos();
    double getYPos();
    double getZPos();

private:
    double xPosition, yPosition, zPosition;
};

#endif // DOT_H
