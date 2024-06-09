#include "rotation.h"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "position.h"

RotatorList initRotator(unsigned int size)
{
    // initialize the PositionAssignerList
    // allocate memory for the PositionAssignerList
    RotatorList e = {
        .size = size,
        .count = 0,
        .list = (Rotator *)malloc(size * sizeof(Rotator))
    };

    // quit if the memory allocation failed
    assert(e.list != NULL);
    
    return e;
}

void closeRotator(RotatorList e)
{
    // free the memory allocated for the PositionAssignerList
    free(e.list);
}

Rotator *addRotator(RotatorList *e)
{
    // if the list is full, double the size like a vector
    if (e->count >= e->size)
    {
        e->size = e->size * 2 + 1;
        e->list = (Rotator *)realloc(e->list, e->size * sizeof(Rotator));
        assert(e->list != NULL);
    }
    
    // initialize the new PositionAssignerComponent
    memset(&e->list[e->count], 0, sizeof(Rotator));

    // return the new PositionAssignerComponent
    return &e->list[e->count++];
}

void updateRotators(RotatorList e)
{
    Rotator *const l = e.list;
    for (int i = 0; i < e.count; i++)
    {
        if (l[i].willUpdate)
        {
            l[i].current = l[i].delta;
        }
    }
}

void setRotation(Rotator *r, Rotation deg)
{
    r->current = deg;
    r->willUpdate = 0;
}

void rotateBy(Rotator *r, Rotation deg)
{
    r->delta = r->current + deg;
    r->willUpdate = 1;
}

void rotateByInstant(Rotator *r, Rotation deg)
{
    r->current += deg;
    r->willUpdate = 0;
}