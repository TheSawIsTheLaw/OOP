#ifndef OBJECTLOADER_HPP
#define OBJECTLOADER_HPP

#include "Composite/component.h"
#include "Model/model.h"

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

class ObjectLoader : public ObjectBuilderBase
{
public:
    ObjectLoader(std::shared_ptr<ObjectBuilderBase> builder);
    std::shared_ptr<Component> getObj(std::ifstream &input);

private:
    std::shared_ptr<ObjectBuilderBase> builder;
};

class CameraBuilder : public ObjectBuilderBase
{
public:
    virtual void buildObject() override;
    virtual void buildData(std::ifstream &input) override;
    virtual shared_ptr<Component> getObject() override;

private:
    shared_ptr<CameraBase> _camera = nullptr;
};

class ModelBuilder : public ObjectBuilderBase
{
public:
    virtual void buildObject() override;
    virtual void buildData(std::ifstream &input) override;
    virtual shared_ptr<Component> getObject() override;

private:
    shared_ptr<Model> _model = nullptr;
    Vector<Dot> dots;
    Vector<Edge> edges;
    Vector<Dot> buildDots(std::ifstream &input);
    Vector<Edge> buildEdges(std::ifstream &input);
};

#endif // OBJECTLOADER_HPP
