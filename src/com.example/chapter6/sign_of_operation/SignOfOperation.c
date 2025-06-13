#include <stdio.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int a = 21;
    int b = 20;
    int c;

    c = a / b;
    printf("%d \n", c);


    c = a % b;
    printf("%d \n", c);


    c = a++;
    printf("先赋值后运算：\n");
    printf("%d \n", c);

    c = a--;
    printf("先赋值后运算：\n");
    printf("%d \n", c);

    printf("====================================");

    c = ++b;
    printf("先运算后赋值：\n");
    printf("%d \n", c);

    c = --b;
    printf("先运算后赋值：\n");
    printf("%d \n", c);


    /**
非（~）运算
非运算即取反运算，在二进制中1变0,0变1
110101进行非运算后为:
001010即1010
     */
    printf("========取反运算符，按二进制位进行取反运算。运算规则：============================");
    c = ~61;
    printf("%d \n", c); //-62
    c = ~1;
    printf("%d \n", c);//-2


    printf("0X%p \n", &c);

    return 0;
}

