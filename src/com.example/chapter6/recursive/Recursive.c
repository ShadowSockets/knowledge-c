//C 语言支持递归，即一个函数可以调用其自身。但在使用递归时，程序员需要注意定义一个从函数退出的条件，否则会进入死循环。
//
//递归函数在解决许多数学问题上起了至关重要的作用，比如计算一个数的阶乘、生成斐波那契数列，等等。


#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");

    double factorial(unsigned int i);
    printf("阶乘为：%lf \n", factorial(15));


    int fibonaci(int i);
    for (int i = 0; i < 10; ++i) {
        printf("斐波那契数列-  %d \n", fibonaci(i));
    }

    return 0;
}


//下面的实例使用递归函数计算一个给定的数的阶乘：
double factorial(unsigned int i) {
    if (i <= 1) {
        return 1;
    }
    return i * factorial(i - 1);
}


//下面的实例使用递归函数生成一个给定的数的斐波那契数列：
int fibonaci(int i) {
    if (i == 0) {
        return 0;
    }
    if (i == 1) {
        return 1;
    }
    return fibonaci(i - 1) + fibonaci(i - 2);
}