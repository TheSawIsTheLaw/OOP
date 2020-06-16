#include "carcassmodel.h"
#include "Matrix/matrix.hpp"

CarcassModel::CarcassModel() {}

CarcassModel::~CarcassModel() {}

CarcassModel::CarcassModel(Vector<Dot> ds, Vector<Edge> es) : dots(ds), edges(es) {}

void CarcassModel::move(double dx, double dy, double dz)
{
    Vector<Dot> result(dots.size());
    for (size_t i = 0; i < dots.size(); i++) {
        result[i] = dots[i].move(dx, dy, dz);
    }

    dots = result;
}

void CarcassModel::scale(double coef)
{
    Vector<Dot> result(dots.size());
    for (size_t i = 0; i < dots.size(); i++) {
        result[i] = dots[i].scale(coef);
    }

    dots = result;
}

void CarcassModel::rotate(double angle, axis ax)
{
    Vector<Dot> result(dots.size());
    for (size_t i = 0; i < dots.size(); i++) {
        result[i] = dots[i].rotate(angle, ax);
    }

    dots = result;
}

Vector<Edge> &CarcassModel::getEdges()
{
    return edges;
}

Vector<Dot> &CarcassModel::getDots()
{
    return dots;
}
