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
