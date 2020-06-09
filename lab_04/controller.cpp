#include "controller.h"

#include <QDebug>

Controller::Controller(QObject *parent)
    : QObject(parent),
      currentFloor(START_FLOOR),
      destinations(FLOORS_AMOUNT, false),
      currentState(FREE)
{
}

void Controller::setNewDestinationFloor(short floor)
{
    currentState = BUSY;

    destinations[floor - 1] = true;

    emit setDestinationFloor(floor);
}

void Controller::onFloor(short floor)
{
    if (currentState != BUSY)
        return;
    currentFloor = floor;
    destinations[floor - 1] = false;

    short newFloor = NO_DESTINATION_FLOOR;
    bool isNewFloorFound = false;
    for (int i = 0; i < FLOORS_AMOUNT - 1 && !isNewFloorFound; i++)
    {
        if (destinations[i])
        {
            newFloor = i + 1;
            isNewFloorFound = true;
        }
    }

    if (isNewFloorFound)
        emit setDestinationFloor(newFloor);
    else
        currentState = FREE;
}

void Controller::passedFloor(short floor)
{
    currentFloor = floor;
    qDebug("It's moving! Now we are at floor %d", currentFloor);
}
