#include "componentvisitorbase.h"

RotateVisitor::RotateVisitor(double ang, axis axi) : angle(ang), ax(axi) {}

//DrawVisitor::DrawVisitor(shared_ptr<>...)

MoveVisitor::MoveVisitor(double dx, double dy, double dz) : xDelta(dx), yDelta(dy), zDelta(dz) {}

ScaleVisitor::ScaleVisitor(double coef) : coefficient(coef) {}
