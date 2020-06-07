#include "door.h"

#include "qdebug.h"

Door::Door(QObject *parent) : QObject(parent), currentState(CLOSED) {
    openStateDoorTimer.setInterval(PASSENGER_TIME_SERVICE);
    openStateDoorTimer.setSingleShot(true);

    openDoorTimer.setSingleShot(true);
    closeDoorTimer.setSingleShot(true);

    QObject::connect(&openDoorTimer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&closeDoorTimer, SIGNAL(timeout()), this, SLOT(close()));
    QObject::connect(this, SIGNAL(doorIsOpened()), &openStateDoorTimer,
                     SLOT(start()));
    QObject::connect(&openStateDoorTimer, SIGNAL(timeout()), this,
                     SLOT(startClosing()));
}

void Door::startOpening() {
    doorState tempState = currentState;
    currentState = OPENNING;
    qDebug("Door is opening...");
    if (tempState == CLOSED) {
        openDoorTimer.start(OPEN_CLOSE_DOOR_TIME);
    } else if (tempState == CLOSING) {
        openDoorTimer.start(OPEN_CLOSE_DOOR_TIME -
                            closeDoorTimer.remainingTime());
        closeDoorTimer.stop();
    }
}

void Door::startClosing() {
    if (currentState == CLOSED) {
        emit doorIsClosed();
        return;
    }

    currentState = CLOSING;
    qDebug("Door is closing...");
    closeDoorTimer.start(OPEN_CLOSE_DOOR_TIME);
}

void Door::open() {
    if (currentState != OPENNING)
        return;
    currentState = OPENED;
    qDebug() << "Door is open. Dear passengers! Go aboard!.";
    emit doorIsOpened();
}

void Door::close() {
    if (currentState != CLOSING)
        return;

    currentState = CLOSED;
    qDebug() << "Door is closed.";
    emit doorIsClosed();
}
