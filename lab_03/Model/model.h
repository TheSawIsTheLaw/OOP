#ifndef MODEL_H
#define MODEL_H

#include "dot.h"
#include "edge.h"

#include "Vector/Vector.h"

class Model
{
public:
    Model() = default;

    virtual ~Model() = 0;

    virtual void scale(double coef) = 0;
    virtual void rotate() = 0;
    virtual void move(double dx, double dy, double dz) = 0;
};

#endif // MODEL_H
