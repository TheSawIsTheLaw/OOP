#ifndef MODEL_H
#define MODEL_H

#include "dot.h"
#include "edge.h"

#include "Vector/Vector.h"

class Model
{
public:
    Model();
    Model(Vector<Dot> d, Vector<Edge> e);

    ~Model() = default;

    void scale();
    void rotate();
    void move();

private:
    Vector<Dot> dots;
    Vector<Edge> edges;
};

#endif // MODEL_H
