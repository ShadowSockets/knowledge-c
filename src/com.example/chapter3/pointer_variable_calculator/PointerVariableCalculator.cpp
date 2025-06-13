#include <iostream>

int main(void)
{
	int a[5];
	int * p;
	int * q;

	p = &a[1];
	q = &a[4];

	printf("两个元素相隔的单元: %d", q - p);
	return 0;
}


