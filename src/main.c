// Source 源代码
#include <stdio.h> // 官方库用<>
#include <time.h>
#include "Entity/export.h"

int main() {

    InitWindow(800, 600, "Hello World");

    E_Plane plane;
    plane.pos = (Vector2){400, 300};
    plane.radius = 10;
    plane.color = BLUE;
    plane.speed = 100;

    E_Input input = {0};

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        // ==== Process Input ====
        E_Input_Tick(&input); // ref input

        // ==== Do Logic ====
        Vector2 moveAxis = Vector2Normalize(input.moveAxis);
        E_Plane_Move(&plane, moveAxis, dt);

        // ==== Draw ====
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello World", 10, 10, 20, LIGHTGRAY);

        DrawCircleV(plane.pos, plane.radius, plane.color);
        EndDrawing();

    }

    CloseWindow();

    return 0;

}