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

    if (currentDestinationFloor == NO_DESTINATION_FLOOR)
        currentDestinationFloor = floor;

    if (currentMovementDirection == UP && floor > currentDestinationFloor) {
        currentDestinationFloor = floor;
    } else if (currentMovementDirection == DOWN &&
               floor < currentDestinationFloor)
        currentDestinationFloor = floor;

    nextFloorDestination(floor);
    if (currentFloor > currentDestinationFloor)
        currentMovementDirection = DOWN;
    else
        currentMovementDirection = UP;

    emit setDestinationFloor(floor, currentMovementDirection);
}

void Controller::onFloor(short floor) {
    if (currentState != BUSY)
        return;

    currentFloor = floor;
    isCommonDestination[floor - 1] = false;
    if (currentFloor == currentDestinationFloor) {
        currentDestinationFloor = NO_DESTINATION_FLOOR;
        findNewFloorDestination();
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

void Controller::findNewFloorDestination() {
    int floorFound = false;
    if (currentMovementDirection == UP) {
        for (int i = FLOORS_AMOUNT - 1; i >= 0 && floorFound == false; i--) {
            if (isCommonDestination[i]) {
                i++;
                currentDestinationFloor = i;
                floorFound = true;
            }
        }
    } else {
        for (int i = 0; i < FLOORS_AMOUNT && floorFound == false; i++) {
            if (isCommonDestination[i]) {
                i++;
                currentDestinationFloor = i;
                floorFound = true;
            }
        }
    }
}

bool Controller::nextFloorDestination(short &floor) {
    int state = false;
    bool flag = true;
    if (currentDestinationFloor > currentFloor) {
        for (int i = currentFloor; i <= FLOORS_AMOUNT && flag; i += 1) {
            if (isCommonDestination[i - 1]) {
                floor = i;
                state = true;
                flag = false;
            }
        }
    } else {
        for (int i = currentFloor; i >= 1 && flag; i -= 1) {
            if (isCommonDestination[i - 1]) {
                floor = i;
                state = true;
                flag = false;
                ;
            }
        }
    }
    return state;
}
