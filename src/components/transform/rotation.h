#ifndef ROTATION_H
#define ROTATION_H

#include "position.h"

// Rotation
typedef float Rotation;

// current Rotation and target Rotation for movement
typedef struct
{
    Rotation rotation;
    Rotation delta;
    Position pivot;
    char willRotate;
} RotationAssignerComponent;

// list of Rotation assigners for system to use
typedef struct
{
    unsigned int count;
    RotationAssignerComponent *list;
} RotationAssignerList;

// short wrapper for RotationAssignerComponent
typedef RotationAssignerComponent Rotator;

static inline void updateRotations(RotationAssignerList e)
{
    RotationAssignerComponent *const l = e.list;
    for (int i = 0; i < e.count; i++)
    {
        if (l[i].willRotate)
        {
            l[i].rotation += l[i].delta;
        }
    }
}

#endif // ROTATION_H