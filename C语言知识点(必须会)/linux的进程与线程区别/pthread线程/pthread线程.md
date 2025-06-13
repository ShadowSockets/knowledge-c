#####本文分享如何用 C 进行多线程开发。#####
核心在于 pthread 这个库。
调用 pthread_create()函数就可以创建一个线程。
它的函数原型如下：
```c
#include <pthread.h>
extern int pthread_create(pthread_t *__restrict __newthread,
			   const pthread_attr_t *__restrict __attr,
			   void *(*__start_routine) (void *),
			   void *__restrict __arg);
```
pthread.h 是它的库。
#参数说明： 
第一个参数:  pthread_t* 也就是代表线程实体的指针。
第二个参数:  为了设置线程的属性，一般为 NULL。
第三个参数:  是线程运行时的函数，这是个函数指针。(该函数返回值为void *)(该函数参数为void *);
第四个参数:  也是一个指针，它是用来将数据传递进线程的运行函数。


#下面用一个代码来示例说明。
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//线程函数
void *test(void *ptr) {
    for (int j = 0; j < 8; j++) {
        printf("the pthread running, count: %d\n", j);
        sleep(1);
    }
}

int main(void) {
    pthread_t pId;
    int i, ret;
    //创建线程，线程id为pId
    ret = pthread_create(&pId, NULL, test, NULL);
    if (ret != 0) {
        printf("create pthread error!\n");
        exit(1);
    }

    for (int j = 0; j < 5; j++) {
        printf("main thread running , count : %d\n", j);
        sleep(1);
    }

    printf("main thread will exit when pthread is over\n");
    //等待线程pId的完成
    pthread_join(pId, NULL);
    printf("main thread exit\n");
    return 0;
}
```
[这里还有一个重要的函数 pthread_join()，它的作用是挂起当前的线程，等待指定的线程运行完毕。
在示例代码中主线程等待子线程执行完毕后才继续执行后面的代码。]


###使用gcc编译注意： pthread是一个动态库，编译的时候需要动态链接，不然程序会报错。
例：
```shell
gcc -o test test.c -lpthread
```



########线程与线程之间经常进行数据通讯，前面也提到过，pthread_create()最后一个参数就是用来传递数据的。
但需要特别注意的是它是 void * 的，也是就是无类型指针，这样做的目的是为了保证线程能够接受任意类型的参数，到时候再强制转换就好了。
我们简单做一些改动，如下：
```c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

//线程函数
void *test(void *arg)
{
	int i;
	char* name = (char *)arg;
	for(i=0;i<8;i++)
	{
		printf("the pthread %s running ,count: %d\n",name,i);
		sleep(1); 
	}

}

int main (int argc,char* argv)
{
	pthread_t pId;
	int i,ret;
	//创建子线程，线程id为pId
	ret = pthread_create(&pId,NULL,test,"sub pthread");
	
	if(ret != 0)
	{
		printf("create pthread error!\n");
		exit(1);
	}

	for(i=0;i < 5;i++)
	{
		printf("main thread running ,count : %d\n",i);
		sleep(1);
	}
	
	printf("main thread will exit when pthread is over\n");
	//等待线程pId的完成
	pthread_join(pId,NULL);
	printf("main thread  exit\n");
	return 0;
}
```
在线程创建的时候给子线程传递了它的名字，然后在线程的运行函数中进行了强制转换。