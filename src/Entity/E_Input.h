#ifndef E_INPUT_H__
#define E_INPUT_H__
#endif

#include "import.h"

typedef struct E_Input {

    Vector2 moveAxis;

    // 不能在结构体里写函数

} E_Input;

// 相当于 ref E_Input input
void E_Input_Tick(E_Input *input) {
    if (IsKeyDown(KEY_A)) {
        input->moveAxis.x = -1;
    } else if (IsKeyDown(KEY_D)) {
        input->moveAxis.x = 1;
    } else {
        input->moveAxis.x = 0;
    }

    if (IsKeyDown(KEY_W)) {
        input->moveAxis.y = -1;
    } else if (IsKeyDown(KEY_S)) {
        input->moveAxis.y = 1;
    } else {
        input->moveAxis.y = 0;
    }
}