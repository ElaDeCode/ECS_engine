#include "../transform/position.h"
#include "../transform/rotation.h"

#include <raylib.h>

typedef struct CollisionRect
{
    Rectangle collision;
} CollisionRect;

typedef struct CollisionRectList
{
    CollisionRect *objects;
    int count;
} CollisionRectList;

void checkCollisionRects(PositionerList *p, RotatorList *r, CollisionRectList *c)
{
    for (int i = 0; i < p->count; i++)
    {
        CollisionRect *const o1 = &c->objects[i];

        for (int j = 0; j < c->count; j++)
        {
            CollisionRect *const o2 = &c->objects[j];
            if (CheckCollisionRecs(o1->collision, o2->collision))
            {
                p->list[i].willUpdate = 0;
            }
        }
    }
}

void updatePhysics(Positioner *p, Rotator *r)
{
    if (p->willUpdate)
    {
        p->current.x += (p->target.x - p->current.x) * 0.1f;
        p->current.y += (p->target.y - p->current.y) * 0.1f;
    }

    if (r->willUpdate)
    {
        r->current += (r->delta) * 0.1f;
    }
}