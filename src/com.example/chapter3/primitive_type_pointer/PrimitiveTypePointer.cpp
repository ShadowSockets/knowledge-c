#include <stdio.h>

void f(int i) {
	i = 99;
}


void swap_1(int i,int j) {   //函数怎么执行，当程序执行到这个函数时，为方法的所有形参和局部变量分配空间，当函数执行完毕，所分配的空间就释放了
	int t;
	t = i; i = j; j = t;
}


//实参和形参是两个不同变量

int main(void)
{
	int i = 6;
	printf("i = %d\n",i); // 结果：i = 6
	
	f(i);
	printf("i = %d\n",i); // 结果：i = 6 

	return 0;
}


