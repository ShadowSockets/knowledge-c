#include <stdio.h>
#include <stdlib.h>

/**
	算法：
		狭义的算法是与数据的存储方式密切相关
		广义的算法是与数据的存储方式无关

		泛型：利用某种技术达到的效果就是：不同的存储方式，执行的操作是一样的
**/

typedef struct Node {
	int data;
	struct Node * pNext;
} NODE, *PNODE;


int main(void)
{   
	return 0;
}

void sort_list(PNODE pHead) {
	int i, j, t;
	PNODE p, q;
}

/**在pHead所指向的链表的第pos个节点前面插入一个新的节点*/
bool insert_list(PNODE pHead,int pos,int val) {

	int i = 0;
	PNODE p = pHead;

	while (NULL != p && i < pos-1) {
	
		p = p->pNext;
		++i;
	}

	if (i>pos-1 || NULL==p) {
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));

	if (NULL == pNew) {
		printf("动态内存分配失败");
		exit(-1);
	}
}
