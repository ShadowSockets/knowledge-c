//自定义方法放在主函数前面;因为编译是从上往下编译的
//如果想放在下面就需要，声明函数

#include <stdio.h>

//函数声明,分号不能丢  [告诉编译器f()为一个函数。]
void f(void);

int main()
{
	f();
	return 0;
}

void f(void) {  //函数如果没有参数，就在括号里写void，标准规范
	printf("哈哈!");
}


