#ifndef E_PLANE_H__
#define E_PLANE_H__
#endif

#include "import.h"

struct E_Plane {
    Vector2 pos;
    float radius;
    Color color;
    float speed;
};
typedef struct E_Plane E_Plane;

void E_Plane_Move(E_Plane *plane, Vector2 moveAxis, float dt) {
    float speed = plane->speed * dt;
    Vector2 dir = Vector2Scale(moveAxis, speed);
    plane->pos = Vector2Add(plane->pos, dir);
}