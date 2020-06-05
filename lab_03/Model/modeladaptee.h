#ifndef MODELADAPTEE_H
#define MODELADAPTEE_H


class ModelAdaptee
{
public:
    virtual ~ModelAdaptee() = 0;

    virtual void rotate() = 0;
    virtual void scale() = 0;
    virtual void move() = 0;
};

#endif // MODELADAPTEE_H
