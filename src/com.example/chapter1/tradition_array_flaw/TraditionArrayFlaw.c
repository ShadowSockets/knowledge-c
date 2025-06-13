#include <stdio.h>

/***
1.数组长度必须事先制定，且只能是常数，不能是变量
	例子：
		int a[5]; //ok
		int len = 5;	int a[len]; //error
**/


void f(void) {
	int a[5] = {1,2,3,4,5}; //20个字节的存储空间程序员无法手动编程释放
						    //它只能在本函数运行完毕时，由系统释放
    printf( "%x",&a[1]);
}

int main(void)
{
    f();
	return 0;
}

