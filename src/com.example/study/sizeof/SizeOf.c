//
// Created by Alex on 2022/5/12.
//

#include <stdio.h>

int main(void) {

    int a = 10;

    int arr[] = {1, 2, 3};

    char str[] = "hello";

    int len_a = sizeof(a);

    int len_arr = sizeof(arr);

    int len_str = sizeof(str);

    printf("len_a=%d,len_arr=%d,len_str=%d\n", len_a, len_arr, len_str);

    //结果是：len_a=4，len_arr=12，len_str=6

    //一个int四个字节，一个char一个字节，字符串默认加了结束字符，所以第一个4，第二个12，第三个6


    //C语言的字符串末位是以\0结尾
    char p[] = {'a', 'b', 'c'}, q[] = "abc";
    //定义字符数组 注意:p和q不同-为q分配4个字节的空间 {'a','b','c','\0'}
    printf("%d %d\n", sizeof(p), sizeof(q));

    return 0;
}
