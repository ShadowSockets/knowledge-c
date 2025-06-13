#pragma comment(lib, "ws2_32.lib")
///这句话的前面意思是静态加入一个lib文件
///        也就是库文件
///ws2_32.lib文件，提供了对以下网络相关API的支持，若使用其中的API，则应该将ws2_32.lib加入工程（否则需要动态载入ws2_32.dll）。
///这句话一般出现在网络编程中，需要使用网络API函数的时候，就必须使用这条语句加载ws2_32.lib库或者动态载入ws2_32.dll


#include <stdio.h>

typedef unsigned char myByte;


void function(int *num) {
    //通过改变num对应地址的值来实现值的改变：
    //形参num是一个指针，传递过来的是一个地址值，解引用即可访问到这个地址值映射的值
    *num = 100;
}

int main() {
    printf("%d\r\n", sizeof(intptr_t));
    printf("%u\r\n", sizeof(long long));

    int l1 = sizeof(char *);
    int l2 = sizeof(int *);
    int l3 = sizeof(long *);
    int l4 = sizeof(void *);
    printf("%d %d %d %d \n", l1, l2, l3, l4); //8个字节 8个字节 8个字节 8个字节
    /// 在64位系统中，所有指针变量本身都占用8个字节；
    /// 指针变量的类型只是表示这个指针指向的数据类型；


    int a[2] = {1, 2};
    float f[2] = {1.f, 2.f};
    char s[3] = {'1', '2', '3'};

    int i1 = sizeof(a);
    int i2 = sizeof(f);
    int i3 = sizeof(s);
    printf("%d %d %d \n", i1, i2, i3); //8 8 3
    int i4 = sizeof(a[0]);
    int i5 = sizeof(f[0]);
    int i6 = sizeof(s[0]);
    printf("%d %d %d \n", i1 / i4, i2 / i5, i3 / i6); //2 2 3


    int number;
    number = 1;
    function(&number);
    printf("%d", number);
    return 0;


    printf("Hello World! \n");
    return 0;
}

