#ifndef COMPONENT_H
#define COMPONENT_H

#include "../Camera/camerabase.h"
#include "../Model/model.h"
#include "../Vector/Vector.h"

class Component;

using ComponentIterator = VecIterator<shared_ptr<Component>>;

class Component
{
public:
    Component();
    virtual ~Component() = 0;

    virtual void accept() = 0;
    virtual void add(shared_ptr<Component> element) = 0;
    virtual void del(ComponentIterator &it) = 0;
    virtual bool isComposite() const = 0;

    virtual ComponentIterator begin();
    virtual ComponentIterator end();

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

    virtual void add() override;
    virtual void del() override;

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
