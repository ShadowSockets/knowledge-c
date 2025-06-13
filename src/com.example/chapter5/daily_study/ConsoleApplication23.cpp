#include <iostream>

//逗号表达式
int main(void) {
    int i;
    int j = 2;

    i = (j++, ++j, j + 2, j - 3); //从左到右执行.

    printf("%d\n", i);

    return 0;
}


