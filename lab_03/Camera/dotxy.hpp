#ifndef DOTXY_H
#define DOTXY_H


class DotXY
{
public:
    DotXY() : xCoordinate(0), yCoordinate(0) {}
    DotXY(double x, double y) : xCoordinate(x), yCoordinate(y) {}

    double getXCoordinate() const noexcept { return xCoordinate; }
    double getYCoordinate() const noexcept { return yCoordinate; }
    void setXCoordinate(double coord) noexcept { xCoordinate = coord; }
    void setYCoordinate(double coord) noexcept { yCoordinate = coord; }

private:
    double xCoordinate, yCoordinate;
};

#endif // DOTXY_H
