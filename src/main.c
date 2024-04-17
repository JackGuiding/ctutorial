// Source 源代码
#include "test.h"  // 自定义库用""
#include <stdio.h> // 官方库用<>
#include <time.h>

const int EXIT_CODE_SUCCESS = 0;
const int EXIT_CODE_FAILED = -1;

int main() {
    int a = 3;
    int b = 4;
    int c = Add(a, b);
    printf("%d + %d = %d\r\n", a, b, c);

    return 0;
}