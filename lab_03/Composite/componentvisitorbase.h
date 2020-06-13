#ifndef COMPONENTVISITORBASE_H
#define COMPONENTVISITORBASE_H

#include "../Drawer/drawer.h"
#include "defines.h"

class ModelComponent;
class CameraComponent;
class Composite;

class ComponentVisitorBase
{
public:
    virtual void visit(ModelComponent &) const = 0;
    virtual void visit(CameraComponent &) const = 0;
    virtual void visit(Composite &) const = 0;
};

class MoveVisitor : public ComponentVisitorBase
{
public:
    MoveVisitor(double dx, double dy, double dz);
    virtual void visit(Composite &) const override;
    virtual void visit(ModelComponent &) const override;
    virtual void visit(CameraComponent &) const override;

private:
    double xDelta, yDelta, zDelta;
};

class ScaleVisitor : public ComponentVisitorBase
{
public:
    ScaleVisitor(double coef);
    virtual void visit(Composite &) const override;
    virtual void visit(ModelComponent &) const override;
    virtual void visit(CameraComponent &) const override;

private:
    double coefficient;
};

class RotateVisitor : public ComponentVisitorBase
{
public:
    RotateVisitor(double ang, axis axi);
    virtual void visit(Composite &) const override;
    virtual void visit(ModelComponent &) const override;
    virtual void visit(CameraComponent &) const override;

private:
    double angle;
    axis ax;
};

class DrawVisitor : public ComponentVisitorBase
{
public:
    DrawVisitor(shared_ptr<DrawerBase> draw, shared_ptr<CameraBase> cam);
    virtual void visit(Composite &) const override;
    virtual void visit(ModelComponent &) const override;
    virtual void visit(CameraComponent &) const override;

private:
    shared_ptr<DrawerBase> drawer;
    shared_ptr<CameraBase> camera;
};

#endif // COMPONENTVISITORBASE_H
