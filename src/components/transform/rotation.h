#ifndef ROTATION_H
#define ROTATION_H

#include "../../primitives/vector.h"

typedef float Rotation;

typedef struct Rotator
{
    Rotation current;
    Rotation delta;
    char willUpdate;
} Rotator;

typedef struct RotatorList
{
    unsigned int size;
    unsigned int count;
    Rotator *list;
} RotatorList;

RotatorList initRotator(unsigned int size);
void closeRotator(RotatorList e);
Rotator *addRotator(RotatorList *e);
void updateRotators(RotatorList e);
void setRotation(Rotator *r, Rotation rot);
void rotateBy(Rotator *r, Rotation rot);
void rotateByInstant(Rotator *r, Rotation rot);


#endif // ROTATION_H