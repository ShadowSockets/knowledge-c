#include <stdio.h>

int arr[] = {1, 2, 3, -1};

//在数组的最后一个元素放入“哨兵”值（通常是0、-1或者NULL），这样代码不需要数组大小也可以确定数组的长度；

int main() {

    int array[] = {1, 2, 3};
    int size = sizeof(array) / sizeof(array[0]);
    printf("%d", size);

    return 0;
}