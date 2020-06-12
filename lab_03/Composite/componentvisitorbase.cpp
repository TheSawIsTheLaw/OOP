#include "componentvisitorbase.h"
#include "../Model/carcassmodel.h"

RotateVisitor::RotateVisitor(double ang, axis axi) : angle(ang), ax(axi) {}

//DrawVisitor::DrawVisitor(shared_ptr<>...)

MoveVisitor::MoveVisitor(double dx, double dy, double dz) : xDelta(dx), yDelta(dy), zDelta(dz) {}

ScaleVisitor::ScaleVisitor(double coef) : coefficient(coef) {}

void ScaleVisitor::visit(Composite &composite) const
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

void MoveVisitor::visit(Composite &composite) const
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

void RotateVisitor::visit(Composite &composite) const
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

void ScaleVisitor::visit(ModelComponent &component) const
{
    CarcassModel *reformTo = dynamic_cast<CarcassModel *>(component.getModel().get());
    reformTo->scale(coefficient);
    shared_ptr<Model> ret(reformTo);
    component.setModel(ret);
}
