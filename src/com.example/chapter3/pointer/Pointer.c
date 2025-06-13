#include <stdio.h>

int main(void)
{
    int * p;    //p是指针变量 int * 表示该p变量只能存储int类型变量的地址
    int i = 10;
    int j;

    p = &i;  //获取i的地址
    j = *p;  //取指定地址中存储的数据

    printf("i = %d j = %d",i,j);

    return 0;
}


