#ifndef CONTEXT_H__
#define CONTEXT_H__
#endif

#include "Entity/export.h"
#include <stdlib.h>

typedef struct Context {
    E_Input* input; // 0x10
    E_Plane* plane; // 0x18
} Context;

void Context_Free(Context* ctx) {
    free(ctx->input);
    free(ctx->plane);
    free(ctx);
}