#include <stdio.h>

/// typedef的基本用法
typedef double dd;


/// 我们为什么一定要使用 typedef 定义函数指针呢？
/// 首先，使用 typedef 定义函数指针，代码看起来更简洁，也更不容易出错。
/// 其次，当函数指针作为其它函数的参数，特别是作为返回值时，直接使用的函数指针编译器无法编译。
typedef int (PFun1)(int, int);  // 声明一个函数类型
typedef int (*PFun2)(int, int); // 声明一个函数指针类型
int (*PFun)(int, int);          // 传统形式，定义一个全局函数指针变量


int add(int i1, int i2) {
    printf("%d\n", i1 + i2);
    return i1 + i2;
}


int main() {

    PFun1 *pFun1 = add;
    PFun2 pFun2 = add;
    PFun = add;

    pFun1(1, 2);
    pFun2(3, 4);
    PFun(5, 6);
    add(7, 8);



    // 如何将一个void类型指针，强制转换为函数指针；
    void *data2 = NULL;
    int (*f2)(int) = (int (*)(int)) data2;

    return 0;
}