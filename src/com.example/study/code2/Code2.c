#include <stdio.h>
#include <stdlib.h>

int main() {

    system("chcp 65001");

    int firstNumber, secondNumber, sumOfTwoNumber;

    printf("input two number \n");

    //通过 scanf() 函数接收用户输入的两个整数
    scanf_s("%d %d", &firstNumber, &secondNumber);

    //两个数相加
    sumOfTwoNumber = firstNumber + secondNumber;

    //输出结果
    printf("%d + %d = %d", firstNumber, secondNumber, sumOfTwoNumber);

    return 0;
}


int main1() {
    system("chcp 65001");
    double firstNumber, secondNumber, product;
    printf("输入两个浮点数:");

    //用户输入两个浮点数
    scanf_s("%lf %lf", &firstNumber, &secondNumber);

    //两个浮点数相乘
    product = firstNumber * secondNumber;

    //输出结果，%.2lf 保留两个小数点
    printf("结果 = %.21f", product);

    return 0;
}


int main2() {
    system("chcp 65001");

    char c;
    printf("输入一个字符:");

    //读取用户输入
    scanf_s("%c", &c);

    //%d 显示整数
    //%c 显示对应字符

    printf("%c 的ASCII为 %d", c, c);
    return 0;
}


int main3() {
    system("chcp 65001");

    // dividend 被除数    divisor 除数   quotient 商   remainder 余数
    int dividend, divisor, quotient, remainder;

    printf("输入被除数:");
    scanf_s("%d", &dividend);

    printf("输入除数:");
    scanf_s("%d", &divisor);

    //计算商
    quotient = dividend / divisor;

    //计算余数
    remainder = dividend % divisor;

    printf("商= %d \n", quotient);
    printf("余数 = %d", remainder);

    return 0;
}


int main4() {
    system("chcp 65001");

    char c;
    printf("输入一个字符:");

    //读取用户输入
    sscanf_s("%c", &c);
    //%d 显示整数
    //%c 显示对应字符
    printf("%c ASCII %d", c, c);
    return 0;
}
