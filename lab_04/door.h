#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QTimer>

#include "defines.h"

class Door : public QObject {
    Q_OBJECT

   public slots:
    void startOpening();
    void startClosing();
    void closeDoorIfNeed();


   public:
    explicit Door(QObject *parent = nullptr);

   signals:
    void doorIsClosed();
    void doorIsOpened();

   private slots:
    void open();
    void close();

   private:
    enum doorState { OPENED, OPENNING, CLOSED, CLOSING };

    doorState currentState;
    QTimer openDoorTimer;
    QTimer closeDoorTimer;
    QTimer openStateDoorTimer;
};

#endif // DOOR_H
