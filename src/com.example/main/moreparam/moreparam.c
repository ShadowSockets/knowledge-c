#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/// 1、定义一个函数，最后一个参数为省略号，省略号前面可以设置自定义参数。
/// 2、在函数定义中创建一个 va_list 类型变量，该类型是在 stdarg.h 头文件中定义的。
/// 3、使用 int 参数和 va_start 宏来初始化 va_list 变量为一个参数列表。宏 va_start 是在 stdarg.h 头文件中定义的。
/// 4、使用 va_arg 宏和 va_list 变量来访问参数列表中的每个项。
/// 5、使用宏 va_end 来清理赋予 va_list 变量的内存。

void fun(int a, ...) {
    va_list pp;
    int n = 1;
            va_start(pp, a);
    do {
        printf("第 %d 个参数 =%d\n", n++, a);
        a = va_arg(pp, int);
    } while (a != 0);

            va_end(pp);
}


void funMore(int a, ...) {
    va_list pp;
    int n = 1;
            va_start(pp, a);
    do {
        printf("the parameter %d : \n", n);
        if (n == 1) {
            char *c1 = va_arg(pp, char*);
            printf("%s\n", c1);
        } else {
            int i1 = va_arg(pp, int);
            printf("%d\n", i1);
        }
        n++;
    } while (n < 5);
            va_end(pp);
}


#define BUF_SIZE 80
char buffer[BUF_SIZE];
int vspf(char *fmt, ...) {
    va_list argptr;
    int cnt;
            va_start(argptr, fmt);
    cnt = vsnprintf(buffer, BUF_SIZE, fmt, argptr);
            va_end(argptr);
    return (cnt);
}


int main() {
    system("chcp 65001");

    int p1 = sizeof('a');  //4
    int p11 = sizeof("a"); //2
    int p2 = sizeof(char);
    int p3 = sizeof(int);
    printf("%d %d %d\n", p1, p2, p3); // 4字节 1字节 4字节
    //C语言中的字符常量是int型，因此sizeof('a')是sizeof(int);

    fun(20, 40, 60, 80, 0);


    int iNumber = 30;
    float fNumber = 90.0f;
    char string[4] = "abc";
    vspf("%d %f %s", iNumber, fNumber, string);


    funMore(1, "Mime", 3, 4, 5); //多参数，并且不同数据类型
    return 0;
}


///////////////////////////////////////////////////////////////
void verror(const char *fmt, va_list argp) {
    fprintf(stderr, "error:");
    vfprintf(stderr, fmt, argp);
    fprintf(stderr, "\n");
}

void error(const char *fmt, ...) {
    va_list argp;
            va_start(argp, fmt);
    verror(fmt, argp);
            va_end(argp);
}
///////////////////////////////////////////////////////////////
