#include <stdio.h>
#include <malloc.h>


struct BTNode {
    int data;
    struct BTNode *pLchild; //p是指针 L是左 child是孩子
    struct BTNode *pRchild;
};

struct BTNode *CreateBTree();

int main(void) {
    struct BTNode *pT = createBTree(); //返回根节点的地址

    return 0;
}

struct BTNode *createBTree() {

    struct BTNode *pA = (struct BTNode *) malloc(sizeof(struct BTNode *));
    struct BTNode *pB = (struct BTNode *) malloc(sizeof(struct BTNode *));
    struct BTNode *pC = (struct BTNode *) malloc(sizeof(struct BTNode *));
    struct BTNode *pD = (struct BTNode *) malloc(sizeof(struct BTNode *));
    struct BTNode *pE = (struct BTNode *) malloc(sizeof(struct BTNode *));

    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
}


