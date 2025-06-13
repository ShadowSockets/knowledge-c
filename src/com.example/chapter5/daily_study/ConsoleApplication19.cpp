#include <iostream>

int main() {

    int input = 0;

    printf("请输入您的小票号:\n");
    scanf_s("%d", &input);  //&取地址符号

    printf("%d", input);

    return 0;
}

