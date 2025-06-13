#include <stdio.h>

void test1(int a) {
    printf("%s", "hello \n");
}

int main() {

    //这里将void(*)(int)类型的函数指针重命名为P
    typedef void (*P)(int a);
    //定义一个P类型，也就是void(*)(int)类型的函数 指针，命名为p
    //并将void(*)(int)类型的函数指针test1赋值给p(初始化)
    P p = test1;

    //调用函数操作
    p(1);

    //用解引用的方式调用函数，和上面的完全等价
    (*p)(1);
    //取地址操作
    P p1 = &test1;
    //用取地址的方式调用函数，和上面的完全等价
    p1(1);

    return 0;
}


