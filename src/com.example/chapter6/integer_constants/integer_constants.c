/**

 在 C 中，有两种简单的定义常量的方式：
    1.使用 #define 预处理器。
    2.使用 const 关键字。

 */
#include <stdio.h>

//定义常量方式1
#define LENGTH 10
#define WIDTH 20
#define NEWLINE '\n'

//定义常量方式2
const int L = 20;
const int W = 30;

int main() {

    int area;

    area = LENGTH + WIDTH;

    printf("define constants %d ", area);
    printf("%c", NEWLINE);

    return 0;
}

