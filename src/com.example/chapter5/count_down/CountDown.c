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
    printf("��������",n);
    getchar(); //getchar()�����������ǴӼ�����նˣ�һ��Ϊ���̣���ȡһ���޷����ַ�
    printf("���س�����ʱ.");
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
