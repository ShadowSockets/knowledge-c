#include <stdio.h>

int main(void)
{
	int a[5];    // a是数组名 5是数组元素个数 元素就是变量

	printf("%#X\n",&a[0]);
	printf("%#X", a); //a是数组第一个元素的地址
	return 0;
}


