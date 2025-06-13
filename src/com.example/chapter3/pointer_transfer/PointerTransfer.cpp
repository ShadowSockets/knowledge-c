#include <iostream>

void f(int * p) {
	*p = 6;
}

int main(void)
{
	int i = 5;
	f(&i);
	printf("%d",i);
	return 0;
}


