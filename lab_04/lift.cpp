#include "lift.h"

#include "cabine.h"
#include "controller.h"

Lift::Lift() {
    QObject::connect(&controller, SIGNAL(set_target(int, direction)), &cabine,
                     SLOT(cabin_call(int, direction)));
    QObject::connect(&cabine, SIGNAL(cabineIsPassingFloor(int, direction)),
                     &controller, SLOT(passedFloor(short)));
    QObject::connect(&cabine, SIGNAL(cabineStopped(short)), &controller,
                     SLOT(achieved_floor(int)));
}

void Lift::clickButton(short floor) {
    controller.setNewFloorPurpose(floor);
}
