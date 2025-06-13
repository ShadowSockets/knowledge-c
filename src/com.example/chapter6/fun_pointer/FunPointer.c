//函数指针
//
//函数指针是指向函数的指针变量。
//
//通常我们说的指针变量是指向一个整型、字符型或数组等变量，而函数指针是指向函数。
//
//函数指针可以像一般函数一样，用于调用函数、传递参数。
//
//函数指针变量的声明：

#include <stdio.h>
#include <stdlib.h>


typedef int (*fun_ptr)(int, int); //声明一个指向同样参数、返回值的函数指针类型


typedef int (__stdcall *fun_ptr1)(int, int); //声明一个指向同样参数、返回值的函数指针类型 //__stdcall是一种标准函数约定


int max1(int x, int y) {
    return x > y ? x : y;
};

int main() {
    system("chcp 65001");

    //p是函数指针
    int (*p)(int, int) = &max1; //&可以省略

    int a, b, c, d;

    printf("请输入三个数字：");
    scanf_s("%d %d %d", &a, &b, &c);

    //与直接调用函数等价，d = max(max(a,b),c)
    d = p(p(a, b), c);

    printf("最大的数字是：%d \n", d);

    return 0;
}