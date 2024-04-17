// Source 源代码
#include "Context.h"
#include <stdio.h> // 官方库用<>
#include <stdlib.h> // malloc, calloc, free
#include <time.h>

typedef unsigned long long PTR;

void Yo();

int main() {

    // 栈数组
    int arr[] = {1, 2, 3, 4, 5}; // 栈内存 20b
    arr[0] = 10;
    for (int i = 0; i < 5; i += 1) {
        // printf("%d\n", arr[i]);
    }

    // 堆内存
    int myValue = 10; // 栈内存 4b
    int* heapArr = calloc(5, sizeof(int));
    PTR ptr = (PTR)heapArr;
    heapArr[0] = 10;
    heapArr[1] = 9;
    heapArr[2] = 8;
    heapArr[3] = 7;
    heapArr[4] = 6;
    for (int i = 0; i < 5; i += 1) {
        int* p = heapArr + i; // 取地址 (语法糖)
        int value = *p; // * 解引用, 取地址里的值 
        // printf("%d\n", value);

        int v2 = *(int*)(ptr + i * sizeof(int));
        printf("v2: %d\n", v2);
        // printf("%d\n", heapArr[i]);
    }

    int a = 3; // 栈内存 4b
    // int *aptr = malloc(4); // 4b
    // int *aptr = calloc(1, 4); // 1*4b 内存值清0

    InitWindow(800, 600, "Hello 小飞机");

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