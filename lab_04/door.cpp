#include "door.h"

#include <QDebug>

Door::Door(QObject *parent) : QObject(parent), state(CLOSED) {
    openStateTimer.setInterval(PASSENGER_WAITING);
    openStateTimer.setSingleShot(true);

    openTimer.setSingleShot(true);
    closeTimer.setSingleShot(true);

    QObject::connect(&openTimer, SIGNAL(timeout()), this, SLOT(open()));
    QObject::connect(&closeTimer, SIGNAL(timeout()), this, SLOT(close()));
    QObject::connect(this, SIGNAL(opened_doors()), &openStateTimer,
                     SLOT(start()));
    QObject::connect(&openStateTimer, SIGNAL(timeout()), this,
                     SLOT(start_closing()));
}

void Door::startOpen() {
    if (state == CLOSED) {
        state = OPENING;
        qDebug() << "Door is opening.";
        openTimer.start(CLOSE_OPEN_TIME);
    }
    if (state == CLOSING) {
        state = OPENING;
        qDebug() << "Door is opening.";
        int t = closeTimer.remainingTime();
        closeTimer.stop();
        openTimer.start(CLOSE_OPEN_TIME - t);
    }
}

void Door::startClose() {
    if (state == OPENED) {
        state = CLOSING;
        qDebug() << "Door is closing.";
        closeTimer.start(CLOSE_OPEN_TIME);
    } else if (state == CLOSED) {
        emit doorIsClosed();
    }
}

void Door::open() {
    if (state == OPENING) {
        state = OPENED;
        qDebug() << "Door is open.";
        emit doorIsOpened();
    }
}

void Door::close() {
    if (state == CLOSING) {
        state = CLOSED;
        qDebug() << "Door is closed.";
        emit doorIsClosed();
    }
}
