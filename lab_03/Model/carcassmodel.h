#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include "../Vector/Vector.h"
#include "dot.h"
#include "edge.h"
#include "model.h"

class CarcassModel : public Model
{
public:
    CarcassModel();
    CarcassModel(Vector<Dot> ds, Vector<Edge> es);

    ~CarcassModel() = default;

    void rotate() override;
    void scale() override;
    void move() override;

private:
    Vector<Dot> dots;
    Vector<Edge> edges;
};

#endif // CARCASSMODEL_H
