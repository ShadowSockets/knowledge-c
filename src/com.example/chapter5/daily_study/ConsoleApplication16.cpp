#include <stdio.h>
#include <ctype.h>

int main(void) {
    char answer = 'N';
    double total = 0.0;
    double value = 0.0;
    int count = 0;
    printf("\n This program calculates the average of"" any number of values");
    for (;;) {
        printf("\n Enter a value:");
        fflush(stdin);//清空输入缓存.
        int qq = scanf("%lf", &value);
        total += value;
        ++count;
        printf("Do you want to enter another value?(Y or N):");
        fflush(stdin);//清空输入缓存.
        int ww = scanf("%c", &answer); //没有执行呀
        if (tolower(answer) == 'n')
            break;
    }
    printf("\n The average is %.2lf \n", total / count);

    return 0;
}
