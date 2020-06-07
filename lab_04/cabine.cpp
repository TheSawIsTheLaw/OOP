#include "cabine.h"

#include <QString>

#include "qdebug.h"

Cabine::Cabine(QObject *parent)
    : QObject(parent),
      currentFloor(1),
      destinationFloor(-1),
      hasNewDestinationFloor(false),
      currentState(STOP),
      currentMovementDirection(STAY) {
    passFloorTimer.setSingleShot(true);

    QObject::connect(this, SIGNAL(cabineIsCalled()), &door,
                     SLOT(start_closing()));
    QObject::connect(this, SIGNAL(cabineReachedDestinationFloor(short)), this,
                     SLOT(cabineStopping()));
    QObject::connect(this, SIGNAL(cabineStopped(short)), &door,
                     SLOT(start_openning()));
    QObject::connect(&door, SIGNAL(closed_doors()), this, SLOT(cabineMoves()));
    QObject::connect(&passFloorTimer, SIGNAL(timeout()), this,
                     SLOT(cabineMoves()));
}

void Cabine::cabineMoves() {
    if (hasNewDestinationFloor && currentState == WAIT) {
        currentState = MOVE;
        if (currentFloor == destinationFloor) {
            emit cabineReachedDestinationFloor(currentFloor);
        } else {
            passFloorTimer.start(CROSSING_FLOOR);
        }
    } else if (currentState == MOVE) {
        currentState = MOVE;

        currentFloor += currentMovementDirection;

        if (currentFloor == destinationFloor) {
            emit cabineReachedDestinationFloor(currentFloor);
        } else {
            emit cabinePassingFloor(currentFloor, currentMovementDirection);
            passFloorTimer.start(CROSSING_FLOOR);
        }
    }
}

void Cabine::cabineStopping() {
    if (currentState == MOVE) {
        currentState = STOP;
        qDebug() << "Лифт остановился на этаже "
                 << QString::number(currentFloor) << ".";
        emit cabineStopped(currentFloor);
    }
}

void Cabine::cabineCall(short floor, direction dir) {
    if (currentState == STOP) {
        hasNewDestinationFloor = true;
        currentState = WAIT;
        destinationFloor = floor;

        currentMovementDirection = dir;
        emit cabineIsCalled();
    }
}
