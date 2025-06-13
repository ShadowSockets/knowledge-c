#include <iostream>

void f(int k[]) {
	int i;
	for  (i = 0; i <= sizeof(k); i++)
	{
		printf("%d\n",k[i]);
	}
}

//数组第一个元素地址，数组长度
void f1(int * pArr,int len) {
	int i;
	for (i = 0; i < len;++i) {
		printf("%d ", *(pArr+i));
	}
}

void f2(int * pArr,int len) {

	pArr[3] = 88; //pArr[3] 等价于 *(pArr+3)
}


int main(void)
{
	int a[5] = {1,2,3,4,5};
	int b[6] = {-1,-2,-3,-4,-5,-6};
	int c[100] = { 1,99,22,33 };

	f1(a, 5);

	// *(a+3) 等价于 a[3]
	return 0;
}


