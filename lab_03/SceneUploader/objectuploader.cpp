#include "objectuploader.hpp"
#include <fstream>

bool ObjectBuilderBase::isBuilt()
{
    return isBui;
}

void CameraBuilder::buildObject()
{
    camera.reset(new Camera());
}

void CameraBuilder::buildData(std::ifstream &input)
{
    double x, y, z;
    if (input >> x >> y >> z)
        camera->setCurrentPosition(x, y, z);
    else
    {
        time_t curTime = time(NULL);
        throw InvalidCamera(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }

    if (input >> x >> y >> z)
        camera->setCurrentNormal(x, y, z);
    else
    {
        time_t curTime = time(NULL);
        throw InvalidCamera(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    isBui = true;
}

shared_ptr<Component> CameraBuilder::getObject()
{
    shared_ptr<Component> component(new CameraComponent(camera));
    return component;
}

void ModelBuilder::buildObject()
{
    model.reset(new CarcassModel());
}

void ModelBuilder::buildData(std::ifstream &input)
{
    CarcassModel &mod = dynamic_cast<CarcassModel &>(*model);
    Vector<Dot> &pts = mod.getDots();
    Vector<Edge> &edges = mod.getEdges();
    pts = buildDots(input);
    edges = buildEdges(input);
    isBui = true;
}

Vector<Dot> ModelBuilder::buildDots(std::ifstream &input)
{
    size_t n = 0;
    if (!(input >> n))
    {
        time_t curTime = time(NULL);
        throw InvalidDotNum(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<Dot> tmp;

    double x, y, z;
    for (size_t i = 0; i < n; ++i)
    {
        if (input >> x >> y >> z)
            tmp.push_back(Dot(x, y, z));
        else
        {
            time_t curTime = time(NULL);
            throw InvalidModelData(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
        }
    }

    return tmp;
}

Vector<Edge> ModelBuilder::buildEdges(std::ifstream &input)
{
    size_t n = 0;
    if (!(input >> n))
    {
        time_t curTime = time(NULL);
        throw InvalidDotNum(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
    Vector<Edge> tmp;

    size_t l1, l2;
    for (size_t i = 0; i < n; ++i)
    {
        if (input >> l1 >> l2)
            tmp.push_back(Edge(l1, l2));
        else
        {
            time_t curTime = time(NULL);
            throw InvalidModelData(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
        }
    }
    return tmp;
}

std::shared_ptr<Component> ModelBuilder::getObject()
{
    return shared_ptr<Component>(new ModelComponent(model));
}

ObjectUploader::ObjectUploader(std::shared_ptr<ObjectBuilderBase> bui)
    : builder(bui) {};

std::shared_ptr<Component> ObjectUploader::getObj(std::ifstream &input)
{
    builder->buildObject();
    builder->buildData(input);
    if (builder->isBuilt())
        return builder->getObject();
    else
    {
        time_t curTime = time(NULL);
        throw ObjectBuildFail(__FILE__, typeid(*this).name(), __LINE__, ctime(&curTime));
    }
}
