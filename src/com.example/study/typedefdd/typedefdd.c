#include <stdio.h>

typedef int (*my_fun1)(int, int); ///声明一个指向同样参数,返回值的函数指针类型

int (*my_fun2)(int, int);        ///声明一个指向同样参数,返回值的函数指针

int func1(int n1, int n2) {
    return 0;
}

int func2(int n1, int n2) {
    return 0;
}


int main() {

    //my_fun1 = func1;     /// 编译错误 （说明了添加typedef的声明，表示这是一个指针类型）

    my_fun1 f1 = func1;  /// 正确编译


    my_fun2 = func2;     /// 正确编译 （说明没有添加typedef的声明，表示这是一个指针）

    return 0;
}