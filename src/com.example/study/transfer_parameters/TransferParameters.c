#include <stdio.h>

void swap1(int x, int y);

void swap2(int *px, int *py);

int main() {

    int a = 5;
    int b = 10;

    //值传递
    swap1(a, b);

    //引用传递
    //swap2(&a, &b);

    printf("a = %d , b = %d \n", a, b);
    return 0;
}

//值传递
void swap1(int x, int y) {
    int tmp;
    tmp = x;
    x = y;
    y = tmp;
    printf("x = %d , y = %d \n", x, y);
}

//地址传递
void swap2(int *px, int *py) {
    int tmp;
    tmp = *px; //将地址赋值给临时变量
    *px = *py;
    *py = tmp;
    printf("px = %d , py = %d \n", *px, *py);
}