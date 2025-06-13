#include <stdio.h>

void sort(int * a,int len) {
    int i, j, t;

    for (i = 0; i < len - 1;++i) {
        for (j = 0; j < len - 1 - i;++j) {
            if (a[j] > a[j+1]) {   // > 升序  <降序

                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;

            }
        }
    }
}

int main(void)
{
    int a[6] = {10,2,8,-8,11,0};

    sort(a,6);

    int i;
    for (i = 0; i < 6;++i) {
        printf("%d ",a[i]);
    }
    long s = 1;
    printf(s);
    printf("ss \n");
    return 0;
}

