#include <iostream>

void g(int *p, int *q) {
    *p = 1;
    *q = 2;
}

int main(void) {

    int a = 3, b = 5;
    g(&a, &b);
    printf("i=%d,b=%d", a, b);

    return 0;
}

