#include "lift.h"

Lift::Lift() {
    QObject::connect(&control_panel, SIGNAL(set_target(short, direction)),
                     &lift_cabin, SLOT(cabineCall(short, direction)));
    QObject::connect(&lift_cabin, SIGNAL(cabinePassingFloor(short, direction)),
                     &control_panel, SLOT(passed_floor(short)));
    QObject::connect(&lift_cabin, SIGNAL(cabineStopped(short)), &control_panel,
                     SLOT(achieved_floor(short)));
}

void Lift::click(short floor) {
    control_panel.set_new_target(floor);
}
