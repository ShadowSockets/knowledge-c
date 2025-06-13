#include <stdio.h>

int main() {

    char s[3] = "123"; //c语言没有字符串
    printf("0x%p \n", &s);
    printf("=-=-=---=-=-==--=-=-=-");

    int arr[5] = {1, 2, 3, 4};
    printf("0x%p \n", &arr[0]);
    printf("0x%p \n", &arr[1]);
    printf("0x%p \n", &arr[2]);
    printf("0x%p \n", &arr[3]);
    printf("0x%p \n", &arr[4]);
    printf("0x%p \n", &arr[5]);
    //发现以下地址值是连续的(间隔的4字节就是int占用的字节数)
//    0x00B3F790
//    0x00B3F794
//    0x00B3F798
//    0x00B3F79C
//    0x00B3F7A0

    //打印指针占用几个字节，输出：4
    printf("%d \n", sizeof &arr[5]);


    int i = 0;
    int* q;
    short w = 0;
    double dd = 1.0;
    float ff = 1.0f;

    int iii = i > 0 ? 222 : 333;

    return 0;
}

