//有效位内是准确的，有效位之外就会在一个范围内浮动，幅度有多大就不知道了


#include <iostream>

int main()
{
	float i = 99.9;

	printf("%f\n",i);  //结果为：99.900002
	return 0;
}


