/**
在一个函数内部的变量,只在函数内部使用
**/

#include <stdio.h>
void f(void) { //括号里的void表示:不需要参数
}

double f1(int i) {    //这个函数返回值为10，因为返回值以方法名前的类型为主
	return 10.8;
}

int main(void)
{
    printf_s("tt");
	return 0;
}

