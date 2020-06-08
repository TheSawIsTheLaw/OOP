#include "cabine.h"

#include <QDebug>
#include <QString>

Cabine::Cabine(QObject *parent)
    : QObject(parent),
      currentFloor(START_FLOOR),
      destinationFloor(NO_DESTINATION_FLOOR),
      currentState(STANDING),
      currentMovementDirection(STAND) {
    QObject::connect(this, SIGNAL(cabineStopped(short)), &door,
                     SLOT(startOpening()));
    QObject::connect(this, SIGNAL(cabineIsCalled()), &door,
                     SLOT(startClosing()));

    QObject::connect(this, SIGNAL(cabineReachedDestinationFloor(short)), this,
                     SLOT(cabineStand()));

    passFloorTimer.setSingleShot(true);
    QObject::connect(&passFloorTimer, SIGNAL(timeout()), this,
                     SLOT(cabineMovesBetweenFloors()));

    QObject::connect(&door, SIGNAL(doorIsClosed()), this,
                     SLOT(cabineStartMoving()));
}


// Тотальный бардак. Проходить все этажи сразу нельзя.
void Cabine::cabineStartMoving() {
    if (currentState != GOTREQUEST)
        return;

    currentState = MOVES;
    if (currentFloor == destinationFloor)
        emit cabineReachedDestinationFloor(currentFloor);
    else
        passFloorTimer.start(FLOOR_PASS_TIME);
}

void Cabine::cabineMovesBetweenFloors() {
    if (currentState != MOVES)
        return;

    if (currentFloor != destinationFloor) {
        emit cabinePassingFloor(currentFloor, currentMovementDirection);
        currentFloor += currentMovementDirection;
        passFloorTimer.start(FLOOR_PASS_TIME);
    } else
        emit cabineReachedDestinationFloor(currentFloor);
}

void Cabine::cabineStand() {
    if (currentState != MOVES)
        return;
    currentState = STANDING;
    qDebug("Lift stands on the floor %d", currentFloor);
    emit cabineStopped(currentFloor);
}

void Cabine::cabineCall(short floor, direction dir) {
    currentState = GOTREQUEST;
    destinationFloor = floor;

    currentMovementDirection = dir;
    emit cabineIsCalled();
}
