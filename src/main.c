#include <stdlib.h>

#include <raylib.h>

#include "components/transform/position.h"
#include "components/transform/rotation.h"

static const int screenWidth = 1000;
static const int screenHeight = 800;
static const char *screenTitle = "Hello, World!";

int main()
{
    InitWindow(screenWidth, screenHeight, screenTitle);

    PositionerList positions = initPositioner(1);
    RotatorList rotations = initRotator(1);

    struct
    {
        Rectangle rect;
        Vector2 origin;
        Positioner *positioner;
        Rotator *rotator;
    } player;

    player.rect = (Rectangle){400, 400, 50, 50};
    player.origin = (Vector2){player.rect.width / 2, player.rect.height / 2};
    player.positioner = addPositioner(&positions);
    player.rotator = addRotator(&rotations);

    player.positioner->current.x = player.rect.x;
    player.positioner->current.y = player.rect.y;
    player.rotator->current = 0;

    // set player position to move to
    setPosition(player.positioner, 500, 500);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // moveBy(player.positioner, 1, 1);
        rotateBy(player.rotator, (Rotation)1);
        player.rect.x = player.positioner->current.x;
        player.rect.y = player.positioner->current.y;

        // update player position
        updatePositioners(positions);
        updateRotators(rotations);

        BeginDrawing();

        ClearBackground(BLACK);

        DrawRectanglePro(player.rect, player.origin, player.rotator->current, RED);

        DrawText("Hello, World!", 10, 10, 20, GREEN);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}