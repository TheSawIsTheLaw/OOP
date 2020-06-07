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
    passFloorTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabineIsCalled()), &door,
                     SLOT(startClosing()));
    QObject::connect(this, SIGNAL(cabineReachedDestinationFloor(short)), this,
                     SLOT(cabineStopping()));
    QObject::connect(this, SIGNAL(cabineStopped(short)), &door,
                     SLOT(startOpening()));
    QObject::connect(&door, SIGNAL(doorIsClosed()), this, SLOT(cabineMoves()));
    QObject::connect(&passFloorTimer, SIGNAL(timeout()), this,
                     SLOT(cabineMoves()));
}

void Cabine::cabineMoves() {
    if (hasNewDestinationFloor && currentState == ISWAITINGFOREVENT) {
        currentState = MOVES;
        if (currentFloor == destinationFloor)
            emit cabineReachedDestinationFloor(currentFloor);
        passFloorTimer.start(FLOOR_PASS_TIME);
    } else if (currentState == MOVES) {
        if (currentFloor == destinationFloor)
            emit cabineReachedDestinationFloor(currentFloor);
        else {
            emit cabinePassingFloor(currentFloor, currentMovementDirection);
            passFloorTimer.start(FLOOR_PASS_TIME);
        }
        currentFloor += currentMovementDirection;
    }
}

void Cabine::cabineStopping() {
    if (currentState == MOVES) {
        currentState = STANDING;
        qDebug() << "Лифт остановился на этаже "
                 << QString::number(currentFloor) << ".";
        emit cabineStopped(currentFloor);
    }
}

void Cabine::cabineCall(short floor, direction dir) {
    if (currentState == STANDING) {
        hasNewDestinationFloor = true;
        currentState = ISWAITINGFOREVENT;
        destinationFloor = floor;

        currentMovementDirection = dir;
        emit cabineIsCalled();
    }
}
