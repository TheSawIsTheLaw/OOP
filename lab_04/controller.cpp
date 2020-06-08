#include "controller.h"

#include <QDebug>

Controller::Controller(QObject *parent)
    : QObject(parent),
      currentFloor(START_FLOOR),
      currentDestinationFloor(NO_DESTINATION_FLOOR),
      isCommonDestination(FLOORS_AMOUNT, false),
      currentState(FREE),
      currentMovementDirection(STAND) {}

void Controller::setNewDestinationFloor(short floor) {
    currentState = BUSY;

    isCommonDestination[floor - 1] = true;

    // Тут вновь пытался делать работу за других, выставлял currentDestFloor
    emit setDestinationFloor(floor);
}

// Доработай for по направлению.
void Controller::onFloor(short floor) {
    if (currentState != BUSY)
        return;
    currentFloor = floor;
    isCommonDestination[floor - 1] = false;

    short newFloor = NO_DESTINATION_FLOOR;
    bool isNewFloorFound = false;
    for (int i = 0; i < FLOORS_AMOUNT - 1 && !isNewFloorFound; i++) {
        if (isCommonDestination[i]) {
            newFloor = i + 1;
            isNewFloorFound = true;
        }
    }

    // Зачем-то хотел здесь меня направление движения, хотя мы не отвечаем за это
    // состояние
    if (isNewFloorFound)
        emit setDestinationFloor(newFloor);
    else
        currentState = FREE;
}

void Controller::passedFloor(short floor) {
    currentFloor = floor;
    qDebug("It's moving! Now we are at floor %d", currentFloor);
}
