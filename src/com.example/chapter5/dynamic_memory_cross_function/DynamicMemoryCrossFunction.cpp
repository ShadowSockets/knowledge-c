#include <stdio.h>

struct Student {
	int age;
	float score;
	char sex;
};

/***
  结构体
	为什么需要结构体
		为了表示一些复杂的事物，而普通的基本类型无法满足实际要求
	什么叫做结构体
		把一些基本类型数据组合在一起形成一个新的数据类型，这个叫做结构体
**/

int main(void)
{
	struct Student st = {80,66.6,'F'};
//	int age;
//	float score;
//	char name[100];

//	int age2;
//	float score2;
//	char name2[100];
	return 0;
}
