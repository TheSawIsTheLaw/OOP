#include "door.h"

#include "qdebug.h"

Door::Door(QObject *parent) : QObject(parent), currentState(CLOSED) {
    openDoorTimer.setSingleShot(true);
    QObject::connect(&openDoorTimer, SIGNAL(timeout()), this, SLOT(open()));

    openStateDoorTimer.setInterval(PASSENGER_TIME_SERVICE);
    openStateDoorTimer.setSingleShot(true);
    // doorIsOpened можно оставить, чтобы расширить с следующих дополнениях
    QObject::connect(this, SIGNAL(doorIsOpened()), &openStateDoorTimer,
                     SLOT(start()));
    QObject::connect(&openStateDoorTimer, SIGNAL(timeout()), this,
                     SLOT(startClosing()));

    closeDoorTimer.setSingleShot(true);
    QObject::connect(&closeDoorTimer, SIGNAL(timeout()), this, SLOT(close()));
}

// Переход в это состояние только из состояния Closed
// Исправлено
void Door::startOpening() {
    if (currentState != CLOSED)
        return;

    currentState = OPENNING;
    qDebug("Door is opening...");
    openDoorTimer.start(OPEN_CLOSE_DOOR_TIME);
}

void Door::open() {
    if (currentState != OPENNING)
        return;
    currentState = OPENED;
    qDebug("Door is opened. Dear passengers! Go aboard!");
    emit doorIsOpened();
}

// Пришлось добавить в отдельный слот. Кажется, за это меня убьют.
void Door::closeDoorIfNeed() {
    if (currentState == CLOSED)
        emit doorIsClosed();
    else
        emit startClosing();
}

void Door::startClosing() {
    if (currentState != OPENED)
        return;

    currentState = CLOSING;
    qDebug("Door is closing...");
    closeDoorTimer.start(OPEN_CLOSE_DOOR_TIME);
}


void Door::close() {
    if (currentState != CLOSING)
        return;

    currentState = CLOSED;
    qDebug("Door is closed.");
    emit doorIsClosed();
}
