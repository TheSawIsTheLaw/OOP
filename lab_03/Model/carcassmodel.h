#ifndef CARCASSMODEL_H
#define CARCASSMODEL_H

#include "modelbase.h"

class CarcassModel : public ModelBase
{
   public:
    CarcassModel();

    virtual ~CarcassModel() = default;

    void rotateCarcass();
    void scaleCarcass();
    void moveCarcass();
};

#endif // CARCASSMODEL_H
