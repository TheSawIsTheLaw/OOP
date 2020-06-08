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

    emit setDestinationFloor(floor, currentMovementDirection);
}

void Controller::onFloor(const short floor) {
    currentFloor = floor;
    isCommonDestination[floor - 1] = false;

    if (currentFloor == currentDestinationFloor) {
        currentDestinationFloor = NO_DESTINATION_FLOOR;
        if (currentMovementDirection == UP)
            findNewFloorDestinationUpper();
        else
            findNewFloorDestinationLower();
    }

    short newFloor = NO_DESTINATION_FLOOR;
    if (nextFloorDestination(newFloor)) {
        if (currentFloor > currentDestinationFloor)
            currentMovementDirection = DOWN;
        else
            currentMovementDirection = UP;

        emit setDestinationFloor(newFloor, currentMovementDirection);
    } else
        currentState = FREE;
}

void Controller::passedFloor(short floor) {
    currentFloor = floor;
    qDebug("It's moving! Now we are at floor %d", currentFloor);
}

void Controller::findNewFloorDestinationUpper() {
    bool floorFound = false;
    for (int i = FLOORS_AMOUNT - 1; i >= 0 && floorFound == false; i--) {
        if (isCommonDestination[i]) {
            i++;
            currentDestinationFloor = i;
            floorFound = true;
        }
    }
}

void Controller::findNewFloorDestinationLower() {
    bool floorFound = false;
    for (int i = 0; i < FLOORS_AMOUNT && floorFound == false; i++) {
        if (isCommonDestination[i]) {
            i++;
            currentDestinationFloor = i;
            floorFound = true;
        }
    }
}

bool Controller::nextFloorDestinationUpper(short &floor) {
    bool wasMovement = false;
    for (int i = currentFloor - 1; i < FLOORS_AMOUNT && wasMovement == false;
         i++) {
        if (isCommonDestination[i]) {
            i++;
            floor = i;
            wasMovement = true;
        }
    }
    return wasMovement;
}

bool Controller::nextFloorDestinationLower(short &floor) {
    bool wasMovement = false;
    for (int i = currentFloor - 1; i >= 0 && wasMovement == false; i--) {
        if (isCommonDestination[i]) {
            i++;
            floor = i;
            wasMovement = true;
        }
    }
    return wasMovement;
}

bool Controller::nextFloorDestination(short &floor) {
    bool wasMovement = false;

    if (currentDestinationFloor > currentFloor)
        wasMovement = nextFloorDestinationUpper(floor);
    else if (currentDestinationFloor < currentFloor)
        wasMovement = nextFloorDestinationLower(floor);

    return wasMovement;
}
