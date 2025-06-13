//
// Created by alex on 2024/11/27.
//
#include <stdio.h>

float x = 0, y = 0;

int main()
{
    printf("目标函数:  f(x, y) = x^2 + 2y^2 + xy - 6x - 10y\n");
    printf("x的偏导数: fx(x, y) = 2x + y - 6\n");
    printf("y的偏导数: fy(x, y) = 4y + x - 10\n");
    printf("初始化令x = y = 0, 即 (0, 0)\n");

    int i;
    float lv = 0.2;
    for (i = 1; i <= 80; i++)
    {
        printf("批次[%d] (x,y) = (%f, %f)\n", i, x, y);
        float x1, y1;
        x1 = (2*x + y - 6) * lv;
        y1 = (4*y + x - 10) * lv;
        x = x - x1;
        y = y - y1;
    }

    printf("结果: (x,y) = (%f, %f)\n", x, y);

    return 0;
}