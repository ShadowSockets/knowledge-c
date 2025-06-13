﻿//求1到100奇数和

/**
for循环的执行顺序是：对于for(expr1;expr2;expr3){expr4;}，
①初始化for循环时执行expr1；
②判断expr2是否成立，若成立则执行循环，否则跳出循环；
③若expr2成立，执行循环体中的expr4；
④当循环体内容执行完后，执行expr3；
⑤回到②开始下一轮循环。

**/
#include <stdio.h>

int main() {
    int i;
    int sum = 0;

    for (i = 0; i < 101; ++i) {
        if (i % 2 == 0) {
            sum += i;
        }
    }

    printf("%d\n", sum);

    return 0;
}

