#include <stdio.h>


//引用外部C文件
extern int array[];
extern int arraysz;

int main(void){

    printf("%d",arraysz);

    return 0;
}