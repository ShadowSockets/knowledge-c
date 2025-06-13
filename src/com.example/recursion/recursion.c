#include <stdio.h>


//1、3、5、7。。。
int f(int n) {
    if (n == 1) {
        return 1;
    } else {
        return f(n - 1) + 2;
    }
}


//斐波那契数列
int f1(int n) {
    if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 1;
    } else {
        return (f1(n - 1) + f1(n - 2));
    }
}


//1.2.3.4.....n 求和
int sum(int n) {
    if (n == 1) {
        return 1;
    } else {
        return (sum(n - 1) + n);
    }
}


//求数组前n项之和(n是数组下标)
//sum(arr,n) = sum(arr,n-1) + arr[n];   //递归关系式
//sum(arr,0) = arr[0];  //递归出口
int sum1(int arr[], int n) {
    if (n == 0) {
        return arr[0];
    } else {
        return sum1(arr, n - 1) + arr[n];
    }
}


//求数组前n项最大值
int max(int arr[], int n) {
    if (n == 0) {
        return arr[0];
    }

    if (max(arr, n - 1) > arr[n]) {
        return max(arr, n - 1);
    } else {
        return arr[n];
    }
}


//找数组指定范围内的最大值,L和R为角标
int findMax(int arr[], int L, int R) {
    if (L == R) {
        return arr[L];
    } else {
        int a = arr[L];
        int b = findMax(arr, L + 1, R);
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
}


//求数组指定范围内，所有元素的和
int sum2(int arr[], int L, int R) {
    if (L == R) {
        return arr[L];
    } else {
        return arr[L] + sum2(arr, L + 1, R);
    }
}

//冒泡排序 用递归实现,L和R是角标
void bubble(int arr[], int L, int R) {
    if (L < R) {
        int i;
        for (i = L; i <= R - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        bubble(arr, L, R - 1);
    }
}


//汉诺塔
void hanoi(int n, char A, char B, char C) {
    if (n == 1) {
        printf("%c -> %c\n", A, C);
    } else {
        hanoi(n - 1, A, C, B);
        printf("%c -> %c\n", A, C);
        hanoi(n - 1, B, A, C);
    }
}


//求最大公约数递归算法
// a    b            r
// 72 ÷ 56 = 1 ..... 16
// 56 ÷ 16 = 3 ..... 8
// 16 ÷ 8 =  2 ..... 0
int gcd(int a, int b) {
    int r = a % b;
    if (r == 0) {
        return b;
    } else {
        return gcd(b, r);
    }
}


int main() {


    int i = f(4);
    printf("%d\n", i);


    int i1 = f1(6);
    printf("%d\n", i1);

    int i2 = sum(100);
    printf("%d\n", i2);

    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int i3 = sum1(arr, 8);
    printf("%d\n", i3);


    int arr1[] = {9, 8, 7, 26, 15, 4, 13, 2, 1};
    int i4 = max(arr1, 8);
    printf("%d\n", i4);

    hanoi(2, 'A', 'B', 'C');


    int arr2[] = {9, 8, 7, 26, 15, 4, 13, 2, 1};
    int i5 = findMax(arr2, 0, 6);
    printf("%d\n", i5);


    int arr3[7] = {6, 1, 2, 9, 7, 3, 4};
    bubble(arr3, 0, 6);
    for (int j = 0; j < 7; j++) {
        printf("%d ", arr3[j]);
    }

    return 0;
}