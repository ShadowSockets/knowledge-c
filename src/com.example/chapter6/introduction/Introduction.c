#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main() {

    //添加以下代码，将代码页字符集更改为utf-8：用于解决控制台中文乱码。
    system("chcp 65001");

    printf("00000000000000 \n");

    //为了得到某个类型或某个变量在特定平台上的准确大小，您可以使用 sizeof 运算符。表达式 sizeof(type) 得到对象或类型的存储字节大小。
    printf("int的存储大小：%d \n", sizeof(int));
    printf("float存储最大字节数: %u \n", sizeof(float));
    printf("float最小值: %E\n", FLT_MIN);
    printf("float最大值: %E\n", FLT_MAX);
    printf("精度值: %d\n", FLT_DIG);

    printf("00000000000000 \n");
    return 0;
}

// 所有的 C 语言程序都需要包含 main() 函数。 代码从 main() 函数开始执行。
// /* ... */ 用于注释说明。
// printf() 用于格式化输出到屏幕。printf() 函数在 "stdio.h" 头文件中声明。
// stdio.h 是一个头文件 (标准输入输出头文件) , #include 是一个预处理命令，用来引入头文件。 当编译器遇到 printf() 函数时，如果没有找到 stdio.h 头文件，会发生编译错误。
// return 0; 语句用于表示退出程序。
