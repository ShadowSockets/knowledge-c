//#include <stdio.h>
//#include <stdlib.h>
//#include "pthread.h" //pthread.h是Linux/unix系统的标准库；貌似你的开发环境是windows；你尝试一下能不能从网上clone一份
//
//
///// volatile指定的关键字可能被系统、硬件、进程/线程改变，强制编译器每次从内存中取得该变量的值，
///// 而不是从被优化后的寄存器中读取。例子:硬件时钟;多线程中被多个任务共享的变量等。
//volatile int sharedI = 0;
//
//void increase_num(void);
////pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
//
//int main() {
//
////    int ret;
////    pthread_t thrd1, thrd2, thrd3;
////
////    ret = pthread_create(&thrd1, NULL, (void *) increase_num, NULL);
////    ret = pthread_create(&thrd2, NULL, (void *) increase_num, NULL);
////    ret = pthread_create(&thrd3, NULL, (void *) increase_num, NULL);
////
////    pthread_join(thrd1, NULL);
////    pthread_join(thrd2, NULL);
////    pthread_join(thrd3, NULL);
//
//    printf("sharedI = %d\n", sharedI);
//
//    return 0;
//}
//
//
//void increase_num(void) {
//    long i, tmp;
//    for (i = 0; i <= 100000; i++) {
//        tmp = sharedI;
//        tmp = tmp + 1;
//        sharedI = tmp;
//    }
//}

int main() {
    return 0;
}