#ifndef OBJECTLOADER_HPP
#define OBJECTLOADER_HPP

#include "Camera/camera.h"
#include "Composite/component.h"
#include "Model/carcassmodel.h"

class ObjectBuilderBase
{
public:
    virtual bool isBuilt();
    virtual void buildObject() = 0;
    virtual void buildData(std::ifstream &input) = 0;
    virtual shared_ptr<Component> getObject() = 0;

protected:
    bool isBui = false;
};

class ObjectUploader : public ObjectBuilderBase
{
public:
    ObjectUploader(std::shared_ptr<ObjectBuilderBase> bui);
    std::shared_ptr<Component> getObj(std::ifstream &input);

private:
    std::shared_ptr<ObjectBuilderBase> builder;
};

class CameraBuilder : public ObjectBuilderBase
{
public:
    virtual void buildObject() override;
    virtual void buildData(std::ifstream &input) override;
    virtual std::shared_ptr<Component> getObject() override;

private:
    std::shared_ptr<CameraBase> camera = nullptr;
};

class ModelBuilder : public ObjectBuilderBase
{
public:
    virtual void buildObject() override;
    virtual void buildData(std::ifstream &input) override;
    virtual std::shared_ptr<Component> getObject() override;

private:
    std::shared_ptr<Model> model = nullptr;
    Vector<Dot> dots;
    Vector<Edge> edges;
    Vector<Dot> buildDots(std::ifstream &input);
    Vector<Edge> buildEdges(std::ifstream &input);
};

#endif // OBJECTLOADER_HPP
