
/***
	形参和实参:
	  个数要相同，位置要一一对应，数据类型要相互兼容
***/

#include <stdio.h>

void f(int i) {    // i是一个形参
	printf("%d\n",i);
}


int main(void)
{
	f(5);		// 5是一个实参
	return 0;
}


