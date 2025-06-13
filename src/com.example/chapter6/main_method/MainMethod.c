#include <stdio.h>

/// 应当指出的是，argv[0] 存储程序的名称，argv[1] 是一个指向第一个命令行参数的指针，*argv[n] 是最后一个参数。
/// 如果没有提供任何参数，argc 将为 1，否则，如果传递了一个参数，argc 将被设置为 2。
int main(int argc, char **argv) { //同int main(int argc,char *argv[])

    printf("Program name %s\n", argv[0]);

    int i;
    for (i = 0; i < argc; i++) {
        printf("param--- %s \n", argv[i]);
    }

    if (argc == 2) {
        printf("The argument supplied is %s \n", argv[1]);
    } else if (argc > 2) {
        printf("Too many arguments supplied.\n");
    } else {
        printf("One argument expected.\n");
    }

    return 0;
}


/// int *arr[10];
/// 第一个是指针数组，他本质上是一个数组 ，这个数组里面的所有元素都是指针。


/// int (*arr)[10];  //C语言中运算符的优先级::: https://www.jb51.net/article/37282.htm
/// 第二个是数组指针，他本质上是一个指针，指向数组的首地址。


/// int (arr*)[10]; 该写法语法错误，不能这么写。
/// 第三个该写法语法错误，不能这么写。


/// char *argv[]  和 char **argv 两种写法有区别吗？ 没有.

/// char *argv[]  先解析是数组，然后数组里边存的元素都是指针  /// 那么数组的第一个元素就相当于是一个二级指针喽
/// char **argv   这是一个二级指针，所以这个写法，和上边(char *argv[])的意义是一样的。

