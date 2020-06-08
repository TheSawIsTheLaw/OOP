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
    QObject::connect(this, SIGNAL(cabineIsCalled()), &door, SLOT(moveToCall()));

    QObject::connect(this, SIGNAL(cabineReachedDestinationFloor(short)), this,
                     SLOT(cabineStand()));

    passFloorTimer.setSingleShot(true);
    QObject::connect(&passFloorTimer, SIGNAL(timeout()), this,
                     SLOT(cabineMoves()));

    QObject::connect(&door, SIGNAL(doorIsClosed()), this, SLOT(cabineMoves()));
}


// Тотальный бардак. Проходить все этажи сразу нельзя.
// Исправлено
void Cabine::cabineMoves() {
    if (currentState != GOTREQUEST && currentState != MOVES)
        return;

    if (currentState == GOTREQUEST) {
        currentState = MOVES;
        // В первом случае требуется пройти полный цикл, чтобы не нарушать
        // закономерности, несмотря на аллогичность движения стоящей кабины
        if (currentFloor == destinationFloor)
            emit cabineReachedDestinationFloor(currentFloor);
        else {
            if (destinationFloor > currentFloor)
                currentMovementDirection = UP;
            else
                currentMovementDirection = DOWN;
            passFloorTimer.start(FLOOR_PASS_TIME);
        }
    } else {
        if (currentFloor != destinationFloor) {
            emit cabinePassingFloor(currentFloor);
            currentFloor += currentMovementDirection;
            passFloorTimer.start(FLOOR_PASS_TIME);
        } else
            emit cabineReachedDestinationFloor(currentFloor);
    }
}

void Cabine::cabineStand() {
    if (currentState != MOVES)
        return;
    currentState = STANDING;
    qDebug("Lift stands on the floor %d", currentFloor);
    emit cabineStopped(currentFloor);
}

// Добавлена обработка перехода только из состояния стоит
void Cabine::cabineCall(short floor) {
    if (currentState != STANDING)
        return;

    currentState = GOTREQUEST;
    destinationFloor = floor;

    emit cabineIsCalled();
}
