#include <stdio.h>

int main(void)
{
	int * p; // 等价于 int *p;也等价于 int* p;
	int i = 5;
	p = &i;

	printf("%d\n",*p);


	char * c;
	char ch = 'A';
	c = &ch;
	printf("%c\n",*c);
	return 0;
}


