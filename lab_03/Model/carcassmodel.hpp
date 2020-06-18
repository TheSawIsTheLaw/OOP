#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include "../Vector/Vector.hpp"
#include "dot.hpp"
#include "edge.hpp"
#include "model.hpp"

class CarcassModel : public Model
{
public:
    CarcassModel();
    CarcassModel(Vector<Dot> ds, Vector<Edge> es);

    ~CarcassModel();

    void rotate(double angle, axis ax);
    void scale(double coef);
    void move(double dx, double dy, double dz);

    Vector<Edge> &getEdges();
    Vector<Dot> &getDots();
    void setDots(Vector<Dot> newDots);
    void setEdges(Vector<Edge> newEdges);

private:
    Vector<Dot> dots;
    Vector<Edge> edges;
};

#endif // CARCASSMODEL_H
