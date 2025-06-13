/***
	一个指针变量到底占几个字节：
		预备知识：
			sizeof(数据类型)
**/

#include <stdio.h>

int main(void) {
    char ch = 'A';
    int i = 99;
    double x = 66.6;

    char *p = &ch;
    int *q = &i;
    double *r = &x;

    printf("char占字节 = %d int占字节 = %d double占字节 = %d\n", sizeof(p), sizeof(q), sizeof(r));

    return 0;
}

