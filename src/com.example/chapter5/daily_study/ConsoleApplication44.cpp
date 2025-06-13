#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
    int data;           //数据域
    struct Node *pNext; //指针域
} NODE, *PNODE; //NODE 等价于 struct Node		 PNODE等价于struct Node *


int main(void) {
    PNODE pHead = NULL; //等价于 struct Node * pHead = NULL;

    pHead = create_list(); //创建非循环单链表,并将该链表的头结点的地址赋给pHead

    traverse_list(pHead); //遍历pHead

    return 0;
}

PNODE create_list(void) {

    int len; //用来存放有效节点的个数
    int i;
    int val; //用来临时存放用户输入的结点的值

    PNODE pHead = (PNODE) malloc(sizeof(NODE));
    if (NULL == pHead) {
        printf("分配失败！程序终止!\n");
        exit(-1);
    }

    printf("请输入您要生成的链表节点个数:len = ");
    scanf_s("%d", &len);

    for (i = 0; i < len; ++i) {
        printf("请输入第%d个节点的值:", i + 1);
        scanf_s("%d", &val);

        PNODE pNew = (PNODE) malloc(sizeof(NODE));
        if (NULL == pNew) {
            printf("分配失败!");
            exit(-1);
        }

        pNew->data = val;
        pHead->pNext = pNew;
        pNew->pNext = NULL;
    }

}


void traverse_list(PNODE pHead) {
    
}
