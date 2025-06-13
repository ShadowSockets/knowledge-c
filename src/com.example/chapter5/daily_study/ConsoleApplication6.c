#include <stdio.h>

int main(void) {
    char ch = 'A';  // ok
//	char ch = "AB"; // error 因为“AB”是字符串，不能把字符串赋值给单个字符
//	char ch = "A";  // error 不能把双引号的字符，赋值给单个字符  字符串在C中后边其实还有一个\0 只是看不见

//	char ch = 'AB'; // 'AB'是错误的

    printf("%c \n", ch);

    return 0;
}

