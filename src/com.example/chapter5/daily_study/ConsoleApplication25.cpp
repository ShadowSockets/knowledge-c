/***
	int a[5];
	数组的空间一定是连续的
		为n个变量连续分配存储空间
		所有变量数据类型必须相同
		所有变量所占字节大小必须相等

	完全初始化:
		int a[5] = {1,2,3,4,5};

	不完全初始化:
		int a[5] = {1,2,3};

	不初始化,所有元素都是垃圾值:
		int a[5]; 

	清零:
		int a[5] = {0};

		只有在定义数组的同时才能整体赋值，
		其它情况下整体赋值都是错误的
***/

#include <stdio.h>

int main(void) {
    int a[5];

    scanf_s("%d", &a[0]);
    printf("%d\n", a[0]);

    scanf_s("%d", &a[3]);
    printf("%d\n", a[3]);


    for (int i = 0; i < 5; i++) {
        printf("%d", a[i]);
    }
    return 0;
}


