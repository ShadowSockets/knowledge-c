#include <stdio.h>

//函数例子： max是函数名字,i和j是形式参数,简称形参  [void表示函数没有返回值]
void maxDigit(int i, int j) {  //当使用到i和j时，会给i和j分配空间
    if (i > j) {
        printf("%d\n", i);
    } else {
        printf("%d\n", j);
    }
}
//当函数执行完毕，函数所使用的的空间都会释放掉；例如：i和j所使用的的空间


int main(void)   //void表示不接收任何参数
{
    int a, b, c, d, e, f;
    a = 1, b = 2, c = 3, d = 9, e = -5, f = 100;  //逗号表达式  整体的值属于最后的一个的值

    maxDigit(a, b);
    maxDigit(c, d);
    maxDigit(e, f);

/*	if (a > b) {
		printf("%d\n",a);
	}
	else {
		printf("%d\n",b);
	}

	if (c > d) {
		printf("%d\n", c);
	}
	else {
		printf("%d\n", d);
	}

	if (e > f) {
		printf("%d\n", e);
	}
	else {
		printf("%d\n", f);
	}
*/
    return 0;
}


