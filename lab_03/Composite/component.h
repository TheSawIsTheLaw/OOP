#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Camera/camerabase.h"
#include "../Model/model.h"
#include "../Vector/Vector.h"

class Component
{
public:
    Component();
    virtual ~Component() = 0;

    virtual void accept() = 0;
    virtual void add() = 0;
    virtual void del() = 0;
    virtual bool isComposite() = 0;

    virtual bool isVisible() const noexcept = 0;
};

class ModelComponent : public Component
{
private:
    shared_ptr<Model> model;

public:
    ModelComponent() = delete;
    ModelComponent(const ModelComponent &) = delete;
    ModelComponent(shared_ptr<Model> model);
    ModelComponent &operator=(const ModelComponent &) = default;
    virtual bool isVisible() const noexcept override;
    //    virtual void accept(const BaseComponentVisitor &visitor) override;

    shared_ptr<Model> getModel();
    void setModel(const shared_ptr<Model>);
};

class CameraComponent : public Component
{
private:
    shared_ptr<CameraComponent> camera;

public:
    CameraComponent() = delete;
    CameraComponent(const ModelComponent &) = delete;
    CameraComponent(shared_ptr<CameraBase> camera);
    CameraComponent &operator=(const CameraComponent &) = default;
    virtual bool isVisible() const noexcept override;
    //    virtual void accept(const BaseComponentVisitor &visitor) override;

    shared_ptr<CameraBase> getCamera();
    void setModel(const shared_ptr<CameraBase>);
};

#endif // COMPONENT_H
