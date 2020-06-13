#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Camera/camerabase.h"
#include "../Model/model.h"
#include "../Vector/Vector.h"
#include "componentvisitorbase.h"

class Component;

using ComponentIterator = VecIterator<shared_ptr<Component>>;

class Component
{
public:
    virtual void accept(const ComponentVisitorBase &) = 0;
    virtual bool add(shared_ptr<Component>);
    virtual bool del(ComponentIterator &);
    virtual bool isComposite() const noexcept = 0;

    virtual ComponentIterator begin();
    virtual ComponentIterator end();

    virtual bool isVisible() const noexcept = 0;
};

class Composite : public Component
{
public:
    Composite() = default;
    Composite(const Composite &) = default;
    Composite(Vector<shared_ptr<Component>> components);
    Composite &operator=(Vector<shared_ptr<Component>> components);
    virtual void accept(const ComponentVisitorBase &) override;
    virtual bool isComposite() const noexcept override;
    virtual bool add(shared_ptr<Component> element) override;
    virtual bool del(ComponentIterator &it) override;
    virtual ComponentIterator begin() override;
    virtual ComponentIterator end() override;

private:
    Vector<shared_ptr<Component>> components;
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
    virtual void accept(const ComponentVisitorBase &) override;

    shared_ptr<Model> getModel();
    void setModel(const shared_ptr<Model>);
};

class CameraComponent : public Component
{
private:
    shared_ptr<CameraBase> camera;

public:
    CameraComponent() = delete;
    CameraComponent(const CameraComponent &) = delete;
    CameraComponent(shared_ptr<CameraBase> cam);
    CameraComponent &operator=(const CameraComponent &) = default;
    virtual bool isVisible() const noexcept override;
    virtual void accept(const ComponentVisitorBase &) override;

    shared_ptr<CameraBase> getCamera();
    void setCamera(const shared_ptr<CameraBase>);
};

#endif // COMPONENT_H
