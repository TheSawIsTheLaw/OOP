#ifndef CABINE_H
#define CABINE_H

#include <QObject>

#include "defines.h"
#include "door.h"

class Cabine : public QObject {
    Q_OBJECT
    enum state { MOVE, WAIT, STOP };

   public:
    explicit Cabine(QObject *parent = nullptr);

   signals:
    void cabineisCalled();
    void cabineIsPassingFloor(short floor, direction dir);
    void cabineReachedDestanation(short floor);
    void cabineStopped(short floor);

   public slots:
    void cabineMoves();
    void cabineStoppes();
    void cabineCall(short floor, direction dir);

   private:
    short currentFloor;
    short destinationFloor;
    bool hasNewDestinationFloor;
    state currentState;
    direction currentMovementDirection;
    Door door;
    QTimer PassingFloorTimer;
};

#endif // CABINE_H
