#include "lift.h"

Lift::Lift()
{
    QObject::connect(&controller, SIGNAL(setDestinationFloor(short)), &cabine,
        SLOT(cabineCall(short)));

    QObject::connect(&cabine, SIGNAL(cabinePassingFloor(short)), &controller,
        SLOT(passedFloor(short)));

    QObject::connect(&cabine, SIGNAL(cabineStopped(short)), &controller,
        SLOT(onFloor(short)));
}

void Lift::call(short floor)
{
    controller.setNewDestinationFloor(floor);
}
