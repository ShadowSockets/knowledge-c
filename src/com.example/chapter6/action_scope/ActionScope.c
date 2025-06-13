#include <stdio.h>

//全局变量与局部变量在内存中的区别：
//
//全局变量保存在内存的全局存储区中，占用静态的存储单元；
//局部变量保存在栈中，只有在所在函数被调用时才动态地为变量分配存储单元。


//初始化局部变量和全局变量
//        当局部变量被定义时，系统不会对其初始化，您必须自行对其初始化。定义全局变量时，系统会自动对其初始化，如下所示：
//
//数据类型	初始化默认值
//int	    0
//char	    '\0'
//float	    0
//double	0
//pointer	NULL
//正确地初始化变量是一个良好的编程习惯，否则有时候程序可能会产生意想不到的结果，因为未初始化的变量会导致一些在内存位置中已经可用的垃圾值。


//全局变量声明
int a = 20;

int main() {
    //在主函数中的局部变量声明
    int a = 10;
    int b = 20;
    int c = 0;
    int sum(int, int);

    printf("value of in main() = %d \n", a);
    c = sum(a, b);
    printf("value of in main() = %d \n", c);

    return 0;
}


//添加两个整数的函数
int sum(int a, int b) {

    printf("value of in sum() = %d \n", a);
    printf("value of in sum() = %d \n", b);

    return a + b;
}

