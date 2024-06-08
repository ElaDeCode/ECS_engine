#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "position.h"

PositionAssignerList createPositionAssignerList(unsigned int count)
{
    PositionAssignerList e = {
        .size = count,
        .count = 0,
        .list = (PositionAssignerComponent *)malloc(count * sizeof(PositionAssignerComponent))
    };
    assert(e.list != NULL);
    
    return e;
}

void freePositionAssignerList(PositionAssignerList e)
{
    free(e.list);
}

Positioner *addPositioner(PositionAssignerList *e)
{
    // if the list is full, double the size like a vector
    if (e->count >= e->size)
    {
        e->size = e->size * 2 + 1;
        e->list = (PositionAssignerComponent *)realloc(e->list, e->size * sizeof(PositionAssignerComponent));
        assert(e->list != NULL);
    }
    
    // initialize the new PositionAssignerComponent
    memset(&e->list[e->count], 0, sizeof(PositionAssignerComponent));

    // return the new PositionAssignerComponent
    return &e->list[e->count++];
}

void updatePositions(PositionAssignerList e)
{
    PositionAssignerComponent *const l = e.list;
    for (int i = 0; i < e.count; i++)
    {
        if (l[i].willMove)
        {
            l[i].current = l[i].target;
        }
    }
}

void moveToNext(Positioner *p, float x, float y)
{
    p->target.x = x;
    p->target.y = y;
    p->willMove = 1;
}

void moveToInstant(Positioner *p, float x, float y)
{
    p->current.x = x;
    p->current.y = y;
    p->willMove = 0;
}

void moveByNext(Positioner *p, float x, float y)
{
    p->target.x = p->current.x + x;
    p->target.y = p->current.y + y;
    p->willMove = 1;
}

void moveByInstant(Positioner *p, float x, float y)
{
    p->current.x += x;
    p->current.y += y;
    p->willMove = 0;
}

Position getPosition(Positioner p)
{
    return p.current;
}

Position getTargetPosition(Positioner p)
{
    return p.target;
}