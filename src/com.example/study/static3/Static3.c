// 3. static 修饰函数 - 静态函数
//         函数默认是有外部链接属性的，但是被 static 修饰后，会使得函数失去外部链接属性，变成内部链接属性。
//         所以 static 修饰的函数只能在自己所在的 .c 文件内部使用，不能在其他文件中使用。和 static 修饰全局变量 很像。
// 一起来看下面这个例子:
// ————————————————

#include <stdio.h>

//声明外部符号
extern int Add(int x, int y);

int main(void) {
    int a = 10;
    int b = 20;
    int ret = Add(a, b);
    printf("%d", ret);
    return 0;
}