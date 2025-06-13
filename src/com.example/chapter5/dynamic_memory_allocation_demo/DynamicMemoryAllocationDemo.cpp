#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int a[5];
	int len;
	int * pArr;

	printf("请输入您要存放的元素个数!\n");
	//scanf_s("%d",&len);

	pArr = (int *)malloc(4 * len); //动态构造长度为len的数组


	printf("请输入元素的内容!\n");
	int i;
	for (i = 0; i < len; ++i) {
		scanf("%d", &pArr[i]);
	}


	printf("一位数组内容为:\n");
	for (i = 0; i < len;++i) {
		printf("%d",pArr[i]);
	}

	free(pArr); //释放动态分配的数组
	return 0;
}


