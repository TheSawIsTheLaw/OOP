#include "cabine.h"

#include <QDebug>

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


void Cabine::cabineMoves() {
    if (hasNewDestinationFloor && currentState == WAIT) {
        currentState = MOVE;
        if (currentFloor == destinationFloor) {
            emit cabineReachedDestanation(currentFloor);
        } else {
            PassingFloorTimer.start(FLOOR_PASS);
        }
    } else if (currentState == MOVE) {
        currentState = MOVE;

        currentFloor += currentMovementDirection;

        if (currentFloor == destinationFloor) {
            emit cabineReachedDestanation(currentFloor);
        } else {
            emit cabineIsPassingFloor(currentFloor, currentMovementDirection);
            PassingFloorTimer.start(FLOOR_PASS);
        }
    }
}

void Cabine::cabineStoppes() {
    if (currentState == MOVE) {
        currentState = STOP;
        qDebug() << "Lift stopped on the floor "
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
