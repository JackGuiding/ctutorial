// Source 源代码
#include "Context.h"
#include <stdio.h> // 官方库用<>
#include <stdlib.h> // malloc, calloc, free
#include <time.h>

void Yo();

int main() {

    int a = 3; // 栈内存 4b
    // int *aptr = malloc(4); // 4b
    // int *aptr = calloc(1, 4); // 1*4b 内存值清0

    InitWindow(800, 600, "Hello World");

    Context* ctx = calloc(1, sizeof(Context)); // 0x10

    E_Plane* plane = calloc(1, sizeof(E_Plane)); // 0x100
    plane->pos = (Vector2){400, 300};
    plane->radius = 10;
    plane->color = BLUE;
    plane->speed = 100;
    ctx->plane = plane; // 复制

    E_Input* input = calloc(1, sizeof(E_Input)); // 0x200
    ctx->input = input;  // 复制

    while (!WindowShouldClose()) {

        float dt = GetFrameTime();

        // ==== Process Input ====
        E_Input_Tick(input); // ref input

        // ==== Do Logic ====
        Vector2 moveAxis = Vector2Normalize(input->moveAxis);
        E_Plane_Move(plane, moveAxis, dt);

        // ==== Draw ====
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello World", 10, 10, 20, LIGHTGRAY);

        DrawCircleV(plane->pos, plane->radius, plane->color);
        EndDrawing();

    }

    CloseWindow();

    // GC 的好处
    Context_Free(ctx);

    return 0;

}

void Yo() { printf("Yo\n"); }