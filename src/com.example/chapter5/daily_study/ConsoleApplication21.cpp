#include <iostream>

int main(void) {
    int i;
    char ch;
    scanf_s("%d", &i);
    printf("i = %d\n", i);

    while ((ch = getchar()) != '\n') {  //这段作用可以防止用户的非法输入影响到下次取值,,getchar()方法获取用户的一个输入字符
        continue;
    }

    int j;
    scanf_s("%d", &j);
    printf("j = %d\n", j);
    return 0;
}

