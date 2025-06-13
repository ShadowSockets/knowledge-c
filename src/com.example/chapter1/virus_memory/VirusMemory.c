#include <stdio.h>
#include <malloc.h>

int main(void) {
    while (1) {
        int* p = (int*)malloc(1000);
    }
    return 0;
}

