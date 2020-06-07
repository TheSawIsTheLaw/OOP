#include "door.h"

#include "qdebug.h"

Door::Door(QObject *parent) : QObject(parent), currentState(CLOSED) {
    openStateDoorTimer.setInterval(WAITING_TIME);
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
    if (currentState == CLOSED) {
        currentState = OPENNING;
        qDebug() << "Двери открываются.";
        openDoorTimer.start(DOORS_TIME);
    }
    if (currentState == CLOSING) {
        currentState = OPENNING;
        qDebug() << "Двери открываются.";
        int t = closeDoorTimer.remainingTime();
        closeDoorTimer.stop();
        openDoorTimer.start(DOORS_TIME - t);
    }
}

void Door::startClosing() {
    if (currentState == OPENED) {
        currentState = CLOSING;
        qDebug() << "Двери закрываются.";
        closeDoorTimer.start(DOORS_TIME);
    } else if (currentState == CLOSED) {
        emit doorIsClosed();
    }
}

void Door::open() {
    if (currentState == OPENNING) {
        currentState = OPENED;
        qDebug() << "Двери открыты.\nЛифт ожидает выхода и входа пассажиров.";
        emit doorIsOpened();
    }
}

void Door::close() {
    if (currentState == CLOSING) {
        currentState = CLOSED;
        qDebug() << "Двери закрыты.";
        emit doorIsClosed();
    }
}
