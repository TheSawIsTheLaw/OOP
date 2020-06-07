#include "cabine.h"

Cabine::Cabine(QObject *parent)
    : QObject(parent),
      currentFloor(1),
      destinationFloor(NO_DESTINATION_FLOOR),
      currentState(STOP),
      currentMovementDirection(STAY) {
    PassingFloorTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabineCalled), &door, SLOT(startClosing()));
}
