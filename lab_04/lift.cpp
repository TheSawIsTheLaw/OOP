#include "lift.h"

Lift::Lift() {
    QObject::connect(&control_panel,
                     SIGNAL(setDestinationFloor(short, direction)), &lift_cabin,
                     SLOT(cabineCall(short, direction)));
    QObject::connect(&lift_cabin, SIGNAL(cabinePassingFloor(short, direction)),
                     &control_panel, SLOT(passedFloor(short)));
    QObject::connect(&lift_cabin, SIGNAL(cabineStopped(short)), &control_panel,
                     SLOT(onFloor(short)));
}

void Lift::click(short floor) {
    control_panel.setNewDestinationFloor(floor);
}
