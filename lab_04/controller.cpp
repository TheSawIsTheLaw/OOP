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

void Controller::onFloor(short floor) {
    if (currentState != BUSY)
        return;

    currentFloor = floor;
    isCommonDestination[floor - 1] = false;
    if (currentFloor == currentDestinationFloor) {
        currentDestinationFloor = NO_DESTINATION_FLOOR;
        if (currentMovementDirection == UP)
            findNewFloorDestinationUpper();
        else
            findNewFloorDestinationLower();
    }

    if (nextFloorDestination(floor)) {
        if (currentFloor > currentDestinationFloor)
            currentMovementDirection = DOWN;
        else
            currentMovementDirection = UP;

        emit setDestinationFloor(floor, currentMovementDirection);
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

bool Controller::nextFloorDestination(short &floor) {
    bool doesNextExist = false;
    if (currentDestinationFloor > currentFloor) {
        for (int i = currentFloor - 1;
             i < FLOORS_AMOUNT && doesNextExist == false; i++) {
            if (isCommonDestination[i]) {
                i++;
                floor = i;
                doesNextExist = true;
            }
        }
    } else {
        for (int i = currentFloor - 1; i >= 0 && doesNextExist == false; i--) {
            if (isCommonDestination[i]) {
                i++;
                floor = i;
                doesNextExist = true;
            }
        }
    }
    return doesNextExist;
}
