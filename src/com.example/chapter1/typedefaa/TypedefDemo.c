#include <stdio.h>

typedef int ZHANG;  //重新再取一个名字

typedef struct Student {
    int age;
} ST;

typedef struct Teacher {
    int age;

} *PTeacher; //PTeacher是指针类型


typedef struct Big {

    int age;

} *PBig, Big; //Big等价于struct Big  ,, PBig等价于struct Big *

int main(void) {
    ST st;
    ZHANG i = 20;

    struct Teacher teacher;
    PTeacher pt;
    pt = &teacher;

    printf("i = %d", i);

    return 0;
}


