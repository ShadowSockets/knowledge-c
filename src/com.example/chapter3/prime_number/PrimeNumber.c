#include <stdio.h>
#include <stdbool.h>

bool isPrime() {   // C语言新加的布尔值
    return true;
}


int main()
{

    int val;
    int i;

    /**
     * scanf_s() 的功能虽然与scanf() 相同，但却比 scanf() 安全，因为 scanf_s() 是针对“ scanf()在读取字符串时不检查边界，可能会造成内存泄露”这个问题设计的。
     */
    scanf("%d", &val); //用于读取字符串时，必须提供一个数字以表明最多读取多少位字符，以防止溢出。

    for (i = 2; i < val; ++i) {
        if (val % i == 0) {
            break;
        }
    }

    if (i == val) {   // 如果i自增到val,那么i肯定为素数
        printf("yes!");
    }
    else {
        printf("no!");
    }
    return 0;
}




