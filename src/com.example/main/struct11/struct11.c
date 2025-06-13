#include <stdio.h>

//#pragma pack(n)  作用：C编译器将按照n个字节对齐。
//#pragma pack()   作用：取消自定义字节对齐方式。

#pragma pack(8)

typedef struct data {
    char a;
    double b;
    int c;
} DATA, *PDATA;

int main(int argc, char *argv[]) {
    printf("sizeof(DATA) = %lu\n", sizeof(DATA));
    return 0;
}