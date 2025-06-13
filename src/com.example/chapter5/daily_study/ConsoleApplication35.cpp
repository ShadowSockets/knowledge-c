#include <stdio.h>

//结构体之间不能加减乘除  但可以相互赋值
struct Student {
    int age;
    char name[200];
    int sid;
};

int main(void) {
    struct Student st = {1000, "zhangsan", 20};

    struct Student *pst;
    pst = &st;
    pst->sid = 99; // pst ->sid 等价于 (*pst).sid 等价于 st.sid

    return 0;
}

