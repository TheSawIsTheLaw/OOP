#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>

#include "defines.h"

class Controller : public QObject {
    Q_OBJECT
    enum controllerState { FREE, BUSY };

   public:
    explicit Controller(QObject *parent = nullptr);
    void setNewDestinationFloor(short floor);

   signals:
    void setDestinationFloor(short floor, direction dir);

   public slots:
    void onFloor(const short floor);
    void passedFloor(short floor);

   private:
    short currentFloor;
    short currentDestinationFloor = NO_DESTINATION_FLOOR;

    QVector<bool> isCommonDestination;
    controllerState currentState;
    direction currentMovementDirection;
    bool nextFloorDestination(short &floor);
    bool nextFloorDestinationUpper(short &floor);
    bool nextFloorDestinationLower(short &floor);
    void findNewFloorDestinationUpper();
    void findNewFloorDestinationLower();
};

#endif // CONTROLLER_H
