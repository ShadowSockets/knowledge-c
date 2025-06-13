#include <stdio.h>
#include <stdlib.h>

int count;
char sign; //字符

char string[20]; //字符串

int main() {
    system("chcp 65001");

    printf("请输入小票号码 \n");
    scanf_s("%c", &sign);

    printf("请输入数量 \n");
    scanf_s("%d", &count);

    printf("解析结果 %d === %c \n", count, sign);


    printf("请输入字符串 \n");
    //20是用来指定缓冲区大小的参数，表示最多读取n-1个字符，不加的话，编译器会出错，无法进行正常的字符串输入。
    scanf_s("%s", string, 20);
    printf("你输入的字符串是  %s", string);

    system("pause");

    return 0;
}

