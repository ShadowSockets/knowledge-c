#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

int main(void) {
    int min, sec, n;
    printf("Input min:");
    scanf("d%", &min);
    printf("Input sec:");
    scanf("d%", &sec);
    n = 60 * min + sec;
    printf("计算结果：",n);
    getchar(); //getchar()函数的作用是从计算机终端（一般为键盘）获取一个无符号字符
    printf("按回车倒计时.");
    while (getchar() != '\n') {
    }
    system("cls");
    while (n != 0) {
        printf("%2d:%2d", n / 60, n % 60);
        n = n - 1;
        Sleep(1000);
        system("cls");
    }
    printf("time is over \n");

    return 0;
}
