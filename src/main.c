#include <stdlib.h>

#include <raylib.h>

#include "components/transform/position.h"
#include "components/transform/rotation.h"
#include "components/physics/physics.h"

static const int screenWidth = 1000;
static const int screenHeight = 800;
static const char *screenTitle = "Hello, World!";

static PositionAssignerList positions = {
    .size = 0,
    .count = 0,
    .list = NULL,
};

int main()
{
    InitWindow(screenWidth, screenHeight, screenTitle);

    struct {
        Rectangle rect;
        Positioner *position;
        Rotator *rotation;
    } player;

    player.rect = (Rectangle){400, 400, 50, 50};
    player.position = addPositioner(&positions);

    player.position->current.x = player.rect.x;
    player.position->current.y = player.rect.y;

    // set player position to move to
    moveToInstant(player.position, 500, 500);
    // draw player
    BeginDrawing();
    DrawRectangle(player.position->current.x, player.position->current.y, player.rect.width, player.rect.height, RED);
    EndDrawing();
    WaitTime(1);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        moveByNext(player.position, 1, 1);

        // update player position
        updatePositions(positions);
        DrawRectangle(player.position->current.x, player.position->current.y, player.rect.width, player.rect.height, RED);

        DrawText("Hello, World!", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    return 0;
}