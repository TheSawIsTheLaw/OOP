#include "cabine.h"

Cabine::Cabine(QObject *parent)
    : QObject(parent),
      currentFloor(1),
      destinationFloor(NO_DESTINATION_FLOOR),
      currentState(STOP),
      currentMovementDirection(STAY) {
    PassingFloorTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabineCalled), &door, SLOT(startClose()));
    QObject::connect(this, SIGNAL(cabineReachedDestination()), this,
                     SLOT(cabineStoppes));
    QObject::connect(this, SIGNAL(cabineStopped), &door, SLOT(startOpen()));
    QObject::connect(&door, SIGNAL(doorIsClosed()), this, SLOT(cabineMoves()));
    QObject::connect(&PassingFloorTimer, SIGNAL(timeout()), this,
                     SLOT(cabin_move()));
}
