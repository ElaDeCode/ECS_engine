#ifndef POSITION_H
#define POSITION_H

// position
typedef struct Position
{
    float x;
    float y;
} Position;

// current position and target position for movement
typedef struct PositionAssignerComponent
{
    Position current;
    Position target;
    char willMove;
} PositionAssignerComponent;

// list of position assigners for system to use
typedef struct PositionAssignerList
{
    unsigned int size;
    unsigned int count;
    PositionAssignerComponent *list;
} PositionAssignerList;

// short wrapper for PositionAssignerComponent
typedef PositionAssignerComponent Positioner;

PositionAssignerList createPositionAssignerList(unsigned int count);
void freePositionAssignerList(PositionAssignerList e);
Positioner *addPositioner(PositionAssignerList *e);
void updatePositions(PositionAssignerList e);
void moveToNext(Positioner *p, float x, float y);
void moveToInstant(Positioner *p, float x, float y);
void moveByNext(Positioner *p, float x, float y);
void moveByInstant(Positioner *p, float x, float y);
Position getPosition(Positioner p);
Position getTargetPosition(Positioner p);

#endif // POSITION_H