// 一元二次方程 例如：ax² + bx² + c = 0

#include <stdio.h>
#include <math.h>

int main(void) {
    //把三个系数保存到计算机中
    int a = 1;
    int b = 2;
    int c = 3;
    double delta; //delta存放的是 b*b -4*a*c

    double x1;  //存放一元二次方程的其中一个解
    double x2;  //存放一元二次方程的其中一个解

    delta = b * b - 4 * a * c;

    if (delta > 0) {
        //两个解
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("该一元二次方程有两个解,x1 = %f,x2 = %f\n", x1, x2);
    } else if (delta == 0) {
        //一个解
        x1 = (-b) / (2 * a);
        x2 = x1;
        printf("该一元二次方程有唯一的解,x1 = x2 = %f\n", x1);
    } else {
        //无解
        printf("无解\0");
    }

    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

//(1) 函数没有参数，返回值为 int 类型。
//int main(void) { /* … */ }

//(2) 函数有两个参数，类型分别是 int 和 char** ，返回值是 int 类型。
//int main(int argc, char* argv[]) { /* … */ }

//这两种定义方式都符合 C 语言标准。除此之外，许多 C 的实现版本还支持第三种、非标准语法的定义方式：
//int main(int argc, char* argv[], char* envs[]) { /* … */ }

//函数返回值是 int，有 3 个参数：第一个是 int，另外两个是 char** 。
//在上面所有的例子中，main（）函数都会把最终的执行状态以整数的方式传递给操作系统。返回值如果是 0 或 EXIT_SUCCESS，就表示程序执行过程一切顺利；任何非 0 的返回值，尤其是 EXIT_FAILURE，则表示程序执行时出现了某种问题。
