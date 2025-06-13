#include <stdio.h>
#include <string.h>
#include <malloc.h>

//在C中，默认的基础数据类型均为signed，现在我们以char为例，说明(signed) char与unsigned char之间的区别。
// 首先在内存中，char与unsigned char没有什么不同，都是一个字节，
// 唯一的区别是，char的最高位为符号位，因此char能表示-128~127,
// unsigned char没有符号位，因此能表示0~255，这个好理解，8个bit，最多256种情况，因此无论如何都能表示256个数字。
//
//使用unsigned char8位字符串有一些小的优点:
// 它更直观,因为我们通常将ASCII码记忆为无符号值,并且在处理二进制数据时,
// 我们更喜欢范围0x00到0xFF,无符号,而不是处理负数.所以我们要使用无符号整数可能更快/更有效,或者在某些处理器上生成更小的代码.
typedef unsigned char u_char;


//实现字符串拷贝，原理是一个字符一个字符的拷贝；
u_char *cpy_string(u_char *dst, u_char *src, size_t n) {
    if (n == 0) {
        return dst;
    }

    while (--n) {
        //*src 读取src指向的那一个内存单元的内容，一个内存单元需要一个地址标识；
        //*dst 写入dst指向的那一个内存单元；

        //由于*src在等于号右边，所以是读取src指向的那一个内存单元的内容；
        //如果*dst在等于号左边，那么是写入dst指向的那一个内存单元；
        *dst = *src;

        if (*dst == '\0') {
            return dst;
        }

        dst++;
        src++;
    }

    *dst = '\0';

    return dst;
}




int main() {

    char *s = "hello,world"; //(s是指向存放hello,world的内存区域的第一个字节的地址)
    char c = *s;    //注意：*s是h，这一点是和基本数据类型不一样的地方；
    printf("%c \n", c);

    int i = 1111;
    int *p = &i;
    int j = *p;     //注意：*p是1111，这点是和字符串不一样的地方；
    printf("%d \n", j);


    u_char str1[] = {};
    u_char str2[] = "nihaoya";
    (void)cpy_string(str1, str2, 7 + 1);
    //(void)这个写法只是一种防止编译器编译时报警告的用法。而此语句在代码中没有具体意义，类似变量的强制转换，不要返回值。
    printf("%s \n", str1);


    return 0;
}




