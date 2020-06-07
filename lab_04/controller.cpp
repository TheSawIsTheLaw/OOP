#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject(parent),
      currentFloor(1),
      currentFloorPurpoise(NO_PURPOISE),
      isPurpoise(FLOOR_AMOUNT, false),
      currentState(FREE),
      currentMovementDirection(STAY) {}

void Controller::setNewFloorPurpose(short floor) {
    currentState = BUSY;
    isPurpoise[floor - 1] = true;

    if (currentFloorPurpoise == NO_PURPOISE)
        currentFloorPurpoise = floor;
    else if (currentMovementDirection == UP && floor > currentFloorPurpoise)
        currentFloorPurpoise = floor;
    else if (currentMovementDirection == DOWN && floor < currentFloorPurpoise)
        currentFloorPurpoise = floor;

    nextFloorPurpoise(floor);
    if (currentFloor > currentFloorPurpoise)
        currentFloorPurpoise = DOWN;
    else
        currentFloorPurpoise = UP;
    emit setFloorPurpose(floor, currentMovementDirection);
}

void Controller::onFloor(short floor) {
    if (currentState != BUSY)
        return;
    currentFloor = floor;
    isPurpoise[floor - 1] = false;
    if (currentFloor == currentFloorPurpoise) {
        currentFloorPurpoise = NO_PURPOISE;
        findNewFloorPurpoise();
    }

    if (nextFloorPurpoise(floor)) {
        if (currentFloor > currentFloorPurpoise)
            currentMovementDirection = DOWN;
        else
            currentMovementDirection = UP;

        emit setFloorPurpose(floor, currentMovementDirection);
    } else
        currentState = FREE;
}

void Controller::passedFloor(short floor) {
    currentFloor = floor;
    qDebug("Current floor is %d", floor);
}

void Controller::findNewFloorPurpoise() {
    int state = false;
    if (currentMovementDirection == UP) {
        for (int i = FLOOR_AMOUNT; i > 0; i--) {
            if (isPurpoise[i - 1] == true) {
                state = true;
                currentFloorPurpoise = i;
            }
        }
    } else {
        for (int i = 1; i <= FLOOR_AMOUNT && !state; i++) {
            if (isPurpoise[i - 1]) {
                state = true;
                currentFloorPurpoise = i;
            }
        }
    }
}

bool Controller::nextFloorPurpoise(short &floor) {
    int state = false;
    bool flag = true;
    if (currentFloorPurpoise > currentFloor) {
        for (int i = currentFloor; i <= FLOOR_AMOUNT && flag; i++) {
            if (isPurpoise[i - 1]) {
                floor = i;
                state = true;
                flag = false;
            }
        }
    } else {
        for (int i = currentFloor; i >= 1 && flag; i--) {
            if (isPurpoise[i - 1]) {
                floor = i;
                state = true;
                flag = false;
                ;
            }
        }
    }
    return state;
}
