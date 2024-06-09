#ifndef POSITION_H
#define POSITION_H

#include "../../primitives/vector.h"

// position
typedef Vector2 Position;

// current position and target position for movement
typedef struct Positioner
{
    Position current;
    Position target;
    char willUpdate;
} Positioner;

// list of position assigners for system to use
typedef struct PositionerList
{
    unsigned int size;
    unsigned int count;
    Positioner *list;
} PositionerList;

PositionerList initPositioner(unsigned int size);
void closePositioner(PositionerList e);
Positioner *addPositioner(PositionerList *e);
void updatePositioners(PositionerList e);
void moveToPosition(Positioner *p, float x, float y);
void setPosition(Positioner *p, float x, float y);
void moveBy(Positioner *p, float x, float y);
void moveByInstant(Positioner *p, float x, float y);
Position getPosition(Positioner p);
Position getTargetPosition(Positioner p);

#endif // POSITION_H