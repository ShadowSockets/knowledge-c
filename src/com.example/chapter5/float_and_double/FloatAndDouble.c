#include <stdio.h>


int main(void) {
    //不同类型数据之间相互赋值的问题
    int i = 45;
    long j = 102345;
    i = j;

    printf("%ld %d\n", i, j);

    float x = 6.6f;
    double y = 8.8;

    printf("%f %lf\n", x, y);
    return 0;
}

