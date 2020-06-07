#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QVector>

#include "defines.h"

class Controller : public QObject {
    Q_OBJECT
    enum states { FREE, BUSY };

   public:
    explicit Controller(QObject *parent = nullptr);
    void setNewFloorPurpose(short floor);

   signals:
    void setFloorPurpose(short floor, direction direct);

   public slots:
    void onFloor(short floor);
    void passedFloor(short floor);

   private:
    short currentFloor;
    int currentFloorPurpoise = -1;

    states currentState;
    direction currentMovementDirection;
    bool nextFloorPurpoise(short &floor);
    void findNewTarget();
};
#endif // CONTROLLER_H
