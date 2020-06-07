#include "controller.h"

#include "iostream"
#include "qdebug.h"

// начальное состояние контрольной панели
Controller::Controller(QObject *parent)
    : QObject(parent),
      currentFloor(1),
      currentDestinationFloor(-1),
      isCommonDestination(NUM_FLOORS, false),
      currentState(FREE),
      CurrentMovementDirection(STAY) {}

void Controller::setNewDestinationFloor(short floor) {
    currentState = BUSY;
    isCommonDestination[floor - 1] = true;

    if (currentDestinationFloor == -1) {
        currentDestinationFloor = floor;
    }

    if ((CurrentMovementDirection == UP && floor > currentDestinationFloor) ||
        (CurrentMovementDirection == DOWN && floor < currentDestinationFloor)) {
        currentDestinationFloor = floor;
    }

    nextFloorDestination(floor); // выбор следующей цели
    CurrentMovementDirection =
        (currentFloor > currentDestinationFloor) ? DOWN : UP;
    emit setDestinationFloor(floor,
                             CurrentMovementDirection); // передача цели кабине
}

void Controller::onFloor(short floor) {
    if (currentState == BUSY) {
        currentFloor = floor;
        isCommonDestination[floor - 1] = false;
        if (currentFloor == currentDestinationFloor) {
            currentDestinationFloor = -1;
            findNewFloorDestination();
        }

        if (nextFloorDestination(floor)) { // если существует еще какой-то вызов

            CurrentMovementDirection =
                (currentFloor > currentDestinationFloor) ? DOWN : UP;

            emit setDestinationFloor(floor, CurrentMovementDirection);
        } else {
            currentState = FREE;
        }
    }
}

void Controller::passedFloor(short floor) {
    currentFloor = floor;
    qDebug() << "Движение, этаж" << floor;
}

void Controller::findNewFloorDestination() {
    int state = false;
    if (CurrentMovementDirection == UP && !state) {
        for (int i = NUM_FLOORS; i >= 1; i--) {
            if (isCommonDestination[i - 1] == true) {
                state = true;
                currentDestinationFloor = i;
            }
        }
    } else {
        for (int i = 1; i <= NUM_FLOORS && !state; i++) {
            if (isCommonDestination[i - 1]) {
                state = true;
                currentDestinationFloor = i;
            }
        }
    }
}

// выбирается следующий этаж, на который поедет лифт
bool Controller::nextFloorDestination(short &floor) {
    int state = false;
    bool flag = true;
    if (currentDestinationFloor > currentFloor) {
        for (int i = currentFloor; i <= NUM_FLOORS && flag; i += 1) {
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
