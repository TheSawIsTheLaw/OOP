#ifndef CABINE_H
#define CABINE_H

#include <QObject>

#include "controller.h"
#include "defines.h"
#include "door.h"

class Cabine : public QObject
{
    Q_OBJECT

   public slots:
    void cabineMoves();
    void cabineStand();
    void cabineCall(short floor); // Убрать direction отсюда к чертям собачьим

   public:
    explicit Cabine(QObject *parent = nullptr);

   signals:
    void cabineIsCalled();
    void cabinePassingFloor(short floor); // Убрать direction
    void cabineReachedDestinationFloor(short floor);
    void cabineStopped(short floor);

   private:
    enum cabineState
    {
        MOVES,
        GOTREQUEST,
        STANDING
    };

    Door door;
    short currentFloor;
    short destinationFloor;
    QTimer passFloorTimer;
    cabineState currentState;
    direction currentMovementDirection;
};

#endif // CABINE_H
