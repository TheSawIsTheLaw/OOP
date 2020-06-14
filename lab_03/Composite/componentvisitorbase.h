#ifndef COMPONENTVISITORBASE_H
#define COMPONENTVISITORBASE_H

#include "../Camera/camerabase.h"
#include "../Drawer/drawer.h"
#include "defines.h"
#include <memory>

class ModelComponent;
class CameraComponent;
class Composite;

class ComponentVisitorBase
{
public:
    virtual void visit(ModelComponent &) = 0;
    virtual void visit(CameraComponent &) = 0;
    virtual void visit(Composite &) = 0;
};

class MoveVisitor : public ComponentVisitorBase
{
public:
    MoveVisitor(double dx, double dy, double dz);
    virtual void visit(Composite &) override;
    virtual void visit(ModelComponent &) override;
    virtual void visit(CameraComponent &) override;

private:
    double xDelta, yDelta, zDelta;
};

class ScaleVisitor : public ComponentVisitorBase
{
public:
    ScaleVisitor(double coef);
    virtual void visit(Composite &) override;
    virtual void visit(ModelComponent &) override;
    virtual void visit(CameraComponent &) override;

private:
    double coefficient;
};

class RotateVisitor : public ComponentVisitorBase
{
public:
    RotateVisitor(double ang, axis axi);
    virtual void visit(Composite &) override;
    virtual void visit(ModelComponent &) override;
    virtual void visit(CameraComponent &) override;

private:
    double angle;
    axis ax;
};

class DrawVisitor : public ComponentVisitorBase
{
public:
    DrawVisitor(std::shared_ptr<DrawerBase> draw, std::shared_ptr<CameraBase> cam);
    virtual void visit(Composite &) override;
    virtual void visit(ModelComponent &) override;
    virtual void visit(CameraComponent &) override;

private:
    std::shared_ptr<DrawerBase> drawer;
    std::shared_ptr<CameraBase> camera;
};

#endif // COMPONENTVISITORBASE_H
