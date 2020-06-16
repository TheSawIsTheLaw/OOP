#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Model/model.h"
#include "Vector/Vector.hpp"
#include "componentvisitorbase.h"

class ComponentVisitorBase;
class Component;

using ComponentIterator = VecIterator<std::shared_ptr<Component>>;

class Component
{
public:
    virtual void accept(ComponentVisitorBase &) = 0;
    virtual bool add(std::shared_ptr<Component>);
    virtual bool del(ComponentIterator &);
    virtual bool isComposite() const noexcept;

    virtual ComponentIterator begin();
    virtual ComponentIterator end();

    virtual bool isVisible() const noexcept;
};

class Composite : public Component
{
public:
    Composite() = default;
    Composite(const Composite &) = default;
    Composite(Vector<std::shared_ptr<Component>> components);
    Composite &operator=(Vector<std::shared_ptr<Component>> components);
    virtual void accept(ComponentVisitorBase &) override;
    virtual bool isComposite() const noexcept override;
    virtual bool add(shared_ptr<Component> element) override;
    virtual bool del(ComponentIterator &it) override;
    virtual ComponentIterator begin() override;
    virtual ComponentIterator end() override;

private:
    Vector<std::shared_ptr<Component>> components;
};

class ModelComponent : public Component
{
public:
    ModelComponent() = delete;
    ModelComponent(const ModelComponent &) = delete;
    ModelComponent(std::shared_ptr<Model> model);
    ModelComponent &operator=(const ModelComponent &) = default;
    virtual bool isVisible() const noexcept override;
    virtual void accept(ComponentVisitorBase &) override;

    std::shared_ptr<Model> getModel();
    void setModel(const std::shared_ptr<Model>);

private:
    std::shared_ptr<Model> model;
};

class CameraComponent : public Component
{
public:
    CameraComponent() = delete;
    CameraComponent(const CameraComponent &) = delete;
    CameraComponent(std::shared_ptr<CameraBase> cam);
    CameraComponent &operator=(const CameraComponent &) = default;
    virtual bool isVisible() const noexcept override;
    virtual void accept(ComponentVisitorBase &) override;

    std::shared_ptr<CameraBase> getCamera();
    void setCamera(const shared_ptr<CameraBase>);

private:
    std::shared_ptr<CameraBase> camera;
};

#endif // COMPONENT_H
