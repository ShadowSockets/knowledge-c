#include <stdio.h>
#include <stdlib.h>

int main() {

    double d[5]; ///现在 balance 是一个可用的数组，可以容纳 5 个类型为 double 的数字。


    printf("d address = %p \n", d);  /// d  是指向d数组d[0]元素的指针。
    printf("d address = %p \n", &d); /// &d 是指向整个d数组的指针。


    /// 其实指向整个d数组的指针当然也是指向整个数组的起始地址也是d[0]。
    /// 所以a和&a的内存地址指针也是一样的。虽然他们的内存指针地址是相同的。
    /// 但是对这两个指针进行加减表示的含义是不同的。
    /// d + 1	   指针移动sizeof(double)8个字节
    /// &d + 1     指针移动sizeof(d)40个字节


    printf("double d size = %d \n", sizeof(d));

    for (int i = 0; i < 5; ++i) {
        d[i] = i + 10.1;
    }
    for (int i = 0; i < 5; ++i) {
        printf("%lf \n", d[i]);
    }


    //如果您省略掉了数组的大小，数组的大小则为初始化时元素的个数。因此，如果：
    double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    for (int i = 0; i < 5; i++) {
        printf("%lf \n", balance[i]);
    }


    //system("pause");

    return 0;
}

