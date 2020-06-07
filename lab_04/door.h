#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "defines.h"

class Door : public QObject {
    Q_OBJECT
    enum doorState { OPENED, CLOSED, OPENNING, CLOSING };

   public:
    explicit Door(QObject *parent = nullptr);

   signals:
    void doorIsClosed();
    void doorIsOpened();

   public slots:
    void startOpening();
    void startClosing();

   private slots:
    void open();
    void close();

   private:
    doorState currentState;
    QTimer openDoorTimer;
    QTimer closeDoorTimer;
    QTimer openStateDoorTimer;
};

#endif // DOOR_H
