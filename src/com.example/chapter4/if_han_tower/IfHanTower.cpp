﻿#include <stdio.h>

void hannuota(int n, char x, char y, char z);

int main(void) {
    char ch1 = 'A';
    char ch2 = 'B';
    char ch3 = 'C';

    int n;
    printf("请输入要移动盘子的个数:");
    scanf("%d", &n);

    hannuota(n, 'A', 'B', 'C');

    return 0;
}


// A：放盘子的那个柱子     B：需要借助的柱子
void hannuota(int n, char A, char B, char C) {
//	如果是一个盘子
//		直接将A柱子上的盘子从A移到C
//	否则 
//		先将X柱子上的n-1个盘子借助C移到B	
//		直接将A柱子上的盘子从A移到C
//		最后将B柱子上的n-1个盘子借助A移到C

    if (1 == n) {
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
    } else {
        hannuota(n - 1, A, C, B);
        printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
        hannuota(n - 1, B, A, C);
    }

}
