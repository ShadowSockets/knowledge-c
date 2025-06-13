#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pNext;
} NODE, *PNODE;


typedef struct Stack {
    PNODE pTop;
    PNODE pBottom;
} STACK, *PSTACK;

void init(PSTACK p);

int main(void) {
    STACK S; //STACK 等价于 struct Stack
    init(&S);
    return 0;
}

void init(PSTACK pS) {
    pS->pTop = (PNODE) malloc(sizeof(NODE));
    if (NULL == pS->pTop) {
        printf("分配失败");
        exit(-1);
    } else {
        pS->pBottom = pS->pTop;
        pS->pTop->pNext = NULL;
    }
}

