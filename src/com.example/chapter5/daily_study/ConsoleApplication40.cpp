#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//定义了一个数组类型,改数据类型的名字叫struct Arr
struct Arr {
    int *pBase; //存储的数组第一个元素的地址
    int len;     //数组所能容纳的最大元素个数
    int cnt;     //当前数组的有效因子
//	int increment; //自动增长因子
};

void init_arr(struct Arr *array, int length);

bool append_arr(struct Arr *pArr, int val);

bool insert_arr(struct Arr *pArr, int pos, int val);

bool delete_arr();

bool get();

bool is_empty(struct Arr *array);

bool is_full(struct Arr *array);

void sort_arr();

void show_arr(struct Arr *array);

void inversion_arr();

int main(void) {
    struct Arr arr;

    init_arr(&arr, 6);

    show_arr(&arr);

    printf("%d\n", arr.len);

    return 0;
}

bool insert_arr(struct Arr *pArr, int pos, int val) {
    int i;

    for (i = pArr->cnt - 1; i >= pos - 1; --i) {
        pArr->pBase[i + 1] = pArr->pBase[i];
    }

    pArr->pBase[pos - 1] = val;

    return true;
}


bool appsend_arr(struct Arr *pArr, int val) {
    if (is_full(pArr)) {
        return false;
    } else {
        pArr->pBase[pArr->cnt] = val;
        (pArr->cnt)++;
        return true;
    }
}

bool is_full(struct Arr *array) {
    return false;
}


void show_arr(struct Arr *pArr) {
}

bool is_empty(struct Arr *pArr) {

    if (0 == pArr->cnt) {
        return false;
    } else {
        return true;
    }
}


void init_arr(struct Arr *array, int length) {

    array->pBase = (int *) malloc(sizeof(int) * length);

    if (NULL == array->pBase) {
        printf("动态内存分配失败!\n");
        exit(-1); //终止整个程序
    } else {
        array->len = length;
        array->cnt = 0;
    }
}


