//
// Created by alex on 2021/11/24.
//
#include "stdio.h"

enum WORDS {
    A, B, C
};

int main() {

    enum WORDS word;
    word = A;
    printf("%d \n", word);
    printf("演示Enum用法 \n");


    int bitcount(unsigned int u);
    int i = bitcount(8);
    printf("%d", i);
    return 0;
}

static int bitcounts[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};

int bitcount(unsigned int u) {
    int n = 0;
    for (; u != 0; u >>= 4) {
        n += bitcounts[u & 0x0f];
    }
    return n;
}