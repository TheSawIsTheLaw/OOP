#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include "modelbase.h"

class CarcassModel : public ModelBase {
public:
    CarcassModel();

    virtual ~CarcassModel();

    void rotateCarcass();
    void scaleCarcass();
    void moveCarcass();
};

#endif // CARCASSMODEL_H
