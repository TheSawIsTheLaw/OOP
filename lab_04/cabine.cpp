#include "cabine.h"

#include <QDebug>
#include <QString>

Cabine::Cabine(QObject *parent)
    : QObject(parent),
      currentFloor(START_FLOOR),
      destinationFloor(NO_DESTINATION_FLOOR),
      hasNewDestinationFloor(false),
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

void Cabine::cabineStartMoving() {
    if (currentState != ISWAITINGFOREVENT || !hasNewDestinationFloor)
        return;

    currentState = MOVES;
    if (currentFloor == destinationFloor)
        emit cabineReachedDestinationFloor(currentFloor);
    else
        passFloorTimer.start(FLOOR_PASS_TIME);
}

void Cabine::cabineMovesBetweenFloors() {
    if (currentState != MOVES || !hasNewDestinationFloor)
        return;

    if (currentFloor == destinationFloor)
        emit cabineReachedDestinationFloor(currentFloor);
    else {
        emit cabinePassingFloor(currentFloor, currentMovementDirection);
        currentFloor += currentMovementDirection;
        passFloorTimer.start(FLOOR_PASS_TIME);
    }
}

void Cabine::cabineStand() {
    if (currentState != MOVES)
        return;
    currentState = STANDING;
    qDebug("Lift stands on the floor %d", currentFloor);
    emit cabineStopped(currentFloor);
}

void Cabine::cabineCall(short floor, direction dir) {
    if (currentState != STANDING)
        return;
    hasNewDestinationFloor = true;
    currentState = ISWAITINGFOREVENT;
    destinationFloor = floor;

    currentMovementDirection = dir;
    emit cabineIsCalled();
}
