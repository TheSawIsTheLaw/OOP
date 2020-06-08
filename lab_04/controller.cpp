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

    if (currentDestinationFloor == NO_DESTINATION_FLOOR) {
        currentDestinationFloor = floor;
        if (currentFloor > currentDestinationFloor)
            currentMovementDirection = DOWN;
        else
            currentMovementDirection = UP;
    } else if (currentMovementDirection == UP &&
               floor > currentDestinationFloor) {
        currentDestinationFloor = floor;
    } else if (currentMovementDirection == DOWN &&
               floor < currentDestinationFloor)
        currentDestinationFloor = floor;

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

    if (isNewFloorFound) {
        if (currentFloor > newFloor)
            currentMovementDirection = DOWN;
        else
            currentMovementDirection = UP;

        emit setDestinationFloor(newFloor);
    } else
        currentState = FREE;
}

void Controller::passedFloor(short floor) {
    currentFloor = floor;
    qDebug("It's moving! Now we are at floor %d", currentFloor);
}
