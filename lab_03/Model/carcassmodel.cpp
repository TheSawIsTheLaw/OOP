#include "carcassmodel.h"
#include "Matrix/matrix.hpp"

CarcassModel::CarcassModel() {}

CarcassModel::CarcassModel(Vector<Dot> ds, Vector<Edge> es) : dots(ds), edges(es) {}

void CarcassModel::move(double dx, double dy, double dz)
{
    Vector<Dot> result(dots.size());
    for (size_t i = 0; i < dots.size(); i++) {
        result[i] = dots[i].move(dx, dy, dz);
    }

    dots = result;
}

void CarcassModel::scale(double coef) {}

void CarcassModel::rotate() {}
