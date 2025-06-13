#先了解一个概念：进程管理块PCB(Process Control Block)
```
1.程序ID（PID、进程句柄）：它是唯一的，一个进程都必须对应一个PID。PID一般是整型数字。

2.特征信息：一般分系统进程、用户进程、或者内核进程等。

3.进程状态：运行、就绪、阻塞，表示进程现在运行情况。

4.优先级：表示获得CPU控制权的优先级大小。

5.通信信息：进程之间的通信关系的反映，由于操作系统会提供通信信道。

6.现场保护区：保护阻塞的进程用。

7.资源需求、分配控制信息。

8.进程实体信息，指明程序路径和名称，进程数据在物理内存还是在交换分区（分页）中。

9.其他信息：工作单位，工作区，文件信息等。

在Unix系统中进程由三部分组成，分别是进程控制块、正文段和数据段。Unix系统中把进程控制块分成proc结构和user结构两部分。

proc存放的是系统经常要查询和修改的信息，需要快速访问，因此常将其装入内存。
```


###############fork一个读进程###############
```c
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
char str[11]={0};
 
int main(int argc, char ** argv) {
    int fd = open("/tmp/test.txt",O_RDWR);
    if(fork() == 0){
	    ssize_t cnt = read(fd,str,10);
	    printf("Child process:%s\n",str);
    } else {
		ssize_t cnt = read(fd,str,10);
	    printf("Parent process:%s\n",str);
    }
    printf("read over\n");
    close(fd);
    return 0;
}
```
```程序执行结果
Parent process:1234567897
read over
Child process:askl12sadf
read over
```
可以发现，两个进程读到的内容并不一样，这是为什么呢？fork出来的进程用的资源不是父进程的一个拷贝吗？
实际上，这跟进程的PCB，也就是struct task_struct有关，进程打开的文件用struct file_struct *files表示，这实际是一个指针。
在fork出子进程后，这个指针也会被copy到子进程的struct task_struct对象中，也就是父进程和子进程的*files是一样的。
也就是使用了指向同一个文件对象的指针，再考虑到读取文件时一般加锁了。
所以父进程读完后，会修改offset，而子进程读取数据的时候，是基于修改后的offset的。就会造成了上述问题。

————————————————
那么，对于写呢？

###############fork一个写进程###############
```c
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
 
char str[11]={0};
char str1[6] = "hello";
char str2[6] = "world";
 
int main(int argc, char ** argv) {
    //O_RDWR读写打开，O_RDONLY只读打开，O_WRONLY只写打开。
    int fd = open("/tmp/test.txt",O_RDWR); 
    if(fork() == 0){
        //	ssize_t cnt = read(fd,str,10);
	    write(fd,str1,6);
	    printf("Child process:%s\n",str);
    } else {
        //	ssize_t cnt = read(fd,str,10);
        write(fd,str2,6);
	    printf("Parent process:%s\n",str);
    }
    printf("write over\n");
    close(fd);
    return 0;
}
```
```程序执行完毕，打开test.txt文件看到
world\00hello\00kl12sadfjsa9d0123
```
可以发现，也是同样的效果，共用了同一个files，造成先后顺序写入内容。
这说明了，使用fork(）得到的父子进程在操作同一个文件的时候，
并不能像两个独立进程操作一个文件一样（如果两次写，只保留一份，后面的会把前面的冲掉）。

