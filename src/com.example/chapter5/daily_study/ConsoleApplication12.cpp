#include <iostream>

//1到100奇数个数

int main(void) {
    int i;
    int cnt = 0;

    for (i = 0; i < 101; ++i) {
        if (i % 2 == 1) {
            ++cnt;
        }
    }
    printf("count = %d \n", cnt);

    return 0;
}

