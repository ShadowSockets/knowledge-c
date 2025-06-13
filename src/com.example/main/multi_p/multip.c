#include <stdio.h>
#include <malloc.h>

typedef struct cycle cycle_t;
struct cycle {
    int i1;
    double i2;
};

int (*f1)(); //函数指针
int (*f2)(int, float); //函数指针


int (*fp1[])();    //fp1是一个数组，数组元素的类型是函数指针，每一个元素所指向的函数的类型是：int (*f1)();
int *(*fp2[])();   //fp2是一个数组，数组元素的类型是函数指针，每一个元素所指向的函数的类型是：int* (*f2)();
int *(*fp3[])(int, float);  //fp3是一个数组，数组元素的类型是函数指针，每一个元素所指向的函数的类型是：int* (*fp3)(int,float);


int main(int argc, char **argv) {

    //打印参数，直到遇到NULL指针(未使用argc),程序名被跳过
    while (*++argv != NULL) {
        printf("%s \n", *argv);
    }

    int s = sizeof(cycle_t);
    printf("%d \n", s); //16
    cycle_t *ct = malloc(s);
    printf("%p \n", ct);     //0000000000B06F70
    printf("%p \n", ct + 1); //0000000000B06F80
    /// “指针变量加1,即向后移动1个位置表示指针变量指向下一个数据元素的首地址。
    /// 而不是在原地址基础上加1。至于真实的地址加了多少,要看该指针指向的数据类型是什么。”


    int i = 0;
    int *p1 = NULL;
    int **p2 = NULL;
    int ***p3 = NULL;
    int ****p4 = NULL;
    p1 = &i;
    p2 = &p1;
    p3 = &p2;
    p4 = &p3;
    printf("%d \n", sizeof(p1)); // 8字节
    printf("%d \n", sizeof(p2)); // 8字节
    printf("%d \n", sizeof(p3)); // 8字节
    printf("%d \n", sizeof(p4)); // 8字节
    /// “指针变量加1,即向后移动1个位置表示指针变量指向下一个数据元素的首地址。
    /// 而不是在原地址基础上加1。至于真实的地址加了多少,要看该指针指向的数据类型是什么。”
    printf("%p \n", p1);    //000000000064FE04
    printf("%p \n", p1 + 1);//000000000064FE08 因为p1指向的数据类型是int，占4个字节；

    printf("%p \n", p2);    //000000000064FDF8
    printf("%p \n", p2 + 1);//000000000064FE00 因为p2指向的数据类型是int*(也就是一个指针)，占8个字节；


    printf("=============================\n");
    //演示：指针和数组的用法完全一样
    char *a1 = "123456";
    char a2[] = {'1', '2', '3', '4', '5', '6', '\0'};
    printf("%c \n", a1[1]);
    printf("%c \n", a2[1]);
    printf("%c \n", *(a1 + 1));
    printf("%c \n", *(a2 + 1));
    return 0;
}