#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
    int *pBase; //代表那个数组
    int front;
    int rear;
} QUEUE;

void init(QUEUE *);

bool en_queue(QUEUE *, int val);

void traverse_queue(QUEUE *);

bool full_queue(QUEUE *);

bool out_queue(QUEUE *, int *);

int main(void) {

    Queue Q;

    init(&Q);

    en_queue(&Q, 1);
    en_queue(&Q, 2);
    en_queue(&Q, 3);
    en_queue(&Q, 4);

    traverse_queue(&Q);

    return 0;
}

void init(QUEUE *pQ) {
    pQ->pBase = (int *) malloc(sizeof(int) * 6);

    pQ->front = 0;
    pQ->rear = 0;
}


bool full_queue(QUEUE *pQ) {
    if ((pQ->rear + 1) % 6 == pQ->front) {
        return true;
    } else {
        return false;
    }
}


bool en_queue(QUEUE *pQ, int val) {
    if (full_queue(pQ)) {
        return false; //入队失败
    } else {
        pQ->pBase[pQ->rear] = val;
        pQ->rear = (pQ->rear + 1) % 6;

        return true;
    }

}

void traverse_queue(QUEUE *pQ) {
    int i = pQ->front;
    while (i != pQ->rear) {
        printf("%d", pQ->pBase[i]);
        i = (i + 1) % 6;
    }
}

bool empty_queue(QUEUE *pQ) {

}

bool out_queue(QUEUE *pQ, int *pVal) {

    if (empty_queue(pQ)) {
        return false;
    } else {
        return true;
    }

}


