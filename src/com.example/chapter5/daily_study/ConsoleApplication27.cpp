﻿#include <stdio.h>

void f(int i);  //这里要声明，否则g()调用f()将报错，  因为定义放在了调用的后边

void g() {
    f(5);    //这里要声明，否则g()调用f()将报错，  因为定义放在了调用的后边
}

void f(int i) {
    return;
}

int main(void) {
    g();

    return 0;
}


