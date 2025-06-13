#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int a[5] = {4,10,2,8,6};

	int len;
	printf("请输入你需要分配的数组的长度:len = ");
	//scanf_s("%d",&len);

	int * pArr =(int *)malloc(sizeof(int) * len);  //只返回的第一个字节地址 【系统就是这么规定的】

	*pArr = 4; //类似于 a[0] = 4;
	pArr[1] = 10; //类似于a[1] = 10;
	
	free(pArr); //把pArr所代表的的动态分配的20个字节的内存释放
	return 0;
}


