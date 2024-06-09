#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "position.h"

PositionerList initPositioner(unsigned int size)
{
    // initialize the PositionAssignerList
    // allocate memory for the PositionAssignerList
    PositionerList e = {
        .size = size,
        .count = 0,
        .list = (Positioner *)malloc(size * sizeof(Positioner))
    };

    // quit if the memory allocation failed
    assert(e.list != NULL);
    
    return e;
}

void closePositioner(PositionerList e)
{
    // free the memory allocated for the PositionAssignerList
    free(e.list);
}

Positioner *addPositioner(PositionerList *e)
{
    // if the list is full, double the size like a vector
    if (e->count >= e->size)
    {
        e->size = e->size * 2 + 1;
        e->list = (Positioner *)realloc(e->list, e->size * sizeof(Positioner));
        assert(e->list != NULL);
    }
    
    // initialize the new PositionAssignerComponent
    memset(&e->list[e->count], 0, sizeof(Positioner));

    // return the new PositionAssignerComponent
    return &e->list[e->count++];
}

void updatePositioners(PositionerList e)
{
    Positioner *const l = e.list;
    for (int i = 0; i < e.count; i++)
    {
        if (l[i].willUpdate)
        {
            l[i].current = l[i].target;
        }
    }
}

void moveToPosition(Positioner *p, float x, float y)
{
    p->target.x = x;
    p->target.y = y;
    p->willUpdate = 1;
}

void setPosition(Positioner *p, float x, float y)
{
    p->current.x = x;
    p->current.y = y;
    p->willUpdate = 0;
}

void moveBy(Positioner *p, float x, float y)
{
    p->target.x = p->current.x + x;
    p->target.y = p->current.y + y;
    p->willUpdate = 1;
}

void moveByInstant(Positioner *p, float x, float y)
{
    p->current.x += x;
    p->current.y += y;
    p->willUpdate = 0;
}