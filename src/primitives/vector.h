#ifndef VECTOR_H
#define VECTOR_H

#include "primitives.h"
#include <raylib.h>

typedef Vector2 v2;
typedef Vector3 v3;
typedef Vector4 v4;

typedef struct
{
    i32 x;
    i32 y;
} Vector2i;

typedef struct
{
    i32 x;
    i32 y;
    i32 z;
} Vector3i;

typedef struct
{
    i32 x;
    i32 y;
    i32 z;
    i32 w;
} Vector4i;

typedef Vector2i v2i;
typedef Vector3i v3i;
typedef Vector4i v4i;

#endif // VECTOR_H