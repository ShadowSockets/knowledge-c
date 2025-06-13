#include <stdio.h>

int main(void)
{
	int val;
	int i;

	scanf("%d",&val);

	for (i = 2; i < val;++i) {
		if (0 == val % i) {
			break;
		}
	}


	if (i == val){
		printf("是质数!");
	}
	else {
		printf("不是质数!");
	}
	return 0;
}

