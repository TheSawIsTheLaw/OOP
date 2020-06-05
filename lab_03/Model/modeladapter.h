#ifndef MODELADAPTER_H
#define MODELADAPTER_H


class ModelAdapter
{
public:
    virtual ~ModelAdapter() = 0;

    virtual void rotateCarcass();
    virtual void scaleCarcass();
    virtual void moveCarcass();
};

#endif // MODELADAPTER_H
