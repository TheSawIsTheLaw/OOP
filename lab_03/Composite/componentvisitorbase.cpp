#include "../Camera/camera.h"
#include "../Model/carcassmodel.h"
#include "component.h"

RotateVisitor::RotateVisitor(double ang, axis axi) : angle(ang), ax(axi) {}

//DrawVisitor::DrawVisitor(shared_ptr<>...)

MoveVisitor::MoveVisitor(double dx, double dy, double dz) : xDelta(dx), yDelta(dy), zDelta(dz) {}

ScaleVisitor::ScaleVisitor(double coef) : coefficient(coef) {}

DrawVisitor::DrawVisitor(shared_ptr<DrawerBase> draw, shared_ptr<CameraBase> cam)
    : drawer(draw), camera(cam)
{}

void ScaleVisitor::visit(Composite &composite)
{
    for (auto &component : composite) {
        if (component->isComposite())
            visit(*static_cast<Composite *>(component.get()));
        else if (component->isVisible())
            visit(*static_cast<ModelComponent *>(component.get()));
        else
            visit(*static_cast<CameraComponent *>(component.get()));
    }
}

void MoveVisitor::visit(Composite &composite)
{
    for (auto &component : composite) {
        if (component->isComposite())
            visit(*static_cast<Composite *>(component.get()));
        else if (component->isVisible())
            visit(*static_cast<ModelComponent *>(component.get()));
        else
            visit(*static_cast<CameraComponent *>(component.get()));
    }
}

void RotateVisitor::visit(Composite &composite)
{
    for (auto &component : composite) {
        if (component->isComposite())
            visit(*static_cast<Composite *>(component.get()));
        else if (component->isVisible())
            visit(*static_cast<ModelComponent *>(component.get()));
        else
            visit(*static_cast<CameraComponent *>(component.get()));
    }
}

void ScaleVisitor::visit(ModelComponent &component)
{
    CarcassModel *reformTo = dynamic_cast<CarcassModel *>(component.getModel().get());
    reformTo->scale(coefficient);
    shared_ptr<Model> ret(reformTo);
    component.setModel(ret);
}

void MoveVisitor::visit(ModelComponent &component)
{
    qDebug("Тут?");
    CarcassModel *reformTo = static_cast<CarcassModel *>((component.getModel()).get());
    reformTo->move(xDelta, yDelta, zDelta);
    shared_ptr<Model> ret(reformTo);
    component.setModel(ret);
}

void MoveVisitor::visit(CameraComponent &component)
{
    Camera *reformTo = dynamic_cast<Camera *>(component.getCamera().get());
    reformTo->movement(xDelta, yDelta, zDelta);
    shared_ptr<CameraBase> ret(reformTo);
    component.setCamera(ret);
}

void RotateVisitor::visit(ModelComponent &component)
{
    CarcassModel *reformTo = dynamic_cast<CarcassModel *>(component.getModel().get());
    reformTo->rotate(angle, ax);
    shared_ptr<Model> ret(reformTo);
    component.setModel(ret);
}

void RotateVisitor::visit(CameraComponent &component)
{
    Camera *reformTo = dynamic_cast<Camera *>(component.getCamera().get());
    reformTo->rotation(angle, ax);
    shared_ptr<Camera> ret(reformTo);
    component.setCamera(ret);
}

void ScaleVisitor::visit(CameraComponent&) {}

void DrawVisitor::visit(Composite &composite)
{
    for (auto &component : composite) {
        if (component->isComposite())
            visit(*static_cast<Composite *>(component.get()));
        else if (component->isVisible())
            visit(*static_cast<ModelComponent *>(component.get()));
        else
            visit(*static_cast<CameraComponent *>(component.get()));
    }
}

void DrawVisitor::visit(CameraComponent &) {}

void DrawVisitor::visit(ModelComponent &model)
{
    shared_ptr<Model> mod = model.getModel();
    CarcassModel *modelToDraw = dynamic_cast<CarcassModel *>(mod.get());
    auto &edges = modelToDraw->getEdges();
    auto &dots = modelToDraw->getDots();

    for (size_t i = 0; i < edges.size(); i++)
    {
        Edge curEdge = edges[i];
        drawer->drawLine(camera->getProjection(dots[curEdge.getFNodeNum()]),
                         camera->getProjection(dots[curEdge.getSNodeNum()]));
    }
}
