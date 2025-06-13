以下函数均返回：读写字节数，-1出错
fd:     文件描述符
vptr:   缓冲区
n:      需要读写的字节长度
maxlen: 最大行长度

##########自定义readn函数
```c
#include <sys/socket.h>
#include <unistd.h>
// R "n" bytes from a descriptor
//来自编程卷的readn函数，从一个描述字读取n字节
size_t readn(int fd, void *vptr, size_t n) {
    size_t nleft;
    size_t nread;
    char *ptr;
    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if ((nread = read(fd, ptr, nleft)) < 0) {
            if (errno == EINTR) {
                nread = 0;  // and call read() again
            } else {
                return -1;
            }
        } else if (nread == 0) {
            break;  // EOF
        }

        nleft -= nread;
        ptr += nread;
    }
    return n - nleft;
}
```




##########自定义writen函数
```c
//writen函数，往一个描述字写n个字节
// Write "n" bytes to a descriptor
size_t writen(int fd,const void * vptr,size_t n){
    size_t nleft;
    size_t nwritten;
    const char * ptr;
    ptr = vptr;
    nleft = n;
    while (nleft > 0) {
        if((nwritten = write(fd,ptr,nleft)) <= 0){
            if(errno == EINTR) {
                nwritten = 0; //and call write() again
            } else {
                return -1;
            }
        }
        nleft -= nwritten;
        ptr += nwritten;
    }
    return n;
}
```



##########自定义readline函数
//readline函数，从一个描述字读文本行，1次1个字节
```c
size_t readline(int fd, void *vptr, size_t maxlen) {
    size_t n, rc;
    char c, *ptr;
    ptr = vptr;
    for (n = 1; n < maxlen; n++) {
        again:
        if ((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;  //ptr++  指针增加
            if (c == '\n') {
                break;
            } else if (rc == 0) {
                if (n == 1) {
                    return 0; //EOF , no data read
                } else {
                    break; //EOF , some data was read
                }
            }
        } else {
            if (errno == EINTR) {
                goto again;
            }
            return -1; // error,errno set by read()
        }
    }
    *ptr = 0; // null terminate like fgets()
    return n;
}
```
注意：函数readline每读一个字节的数据就要调用一次系统的read函数，其效率是非常低的，
我们宁愿调用函数read来取得尽可能多的数据，将其缓冲起来，然后在缓冲区每次检查一个字节，
这可以通过标准I/O库来实现，如下函数是readline的一个较快速版本，它每次最多读MAXLINE个字节，然后一次返回一个字符。



####readline改进版====只需把上面函数(readline)中的read方法，修改为调用my_read方法即可；
```c
#define MAXLINE 2048
static size_t my_read(int fd,char * ptr){
    static unsigned int read_cnt = 0;
    static char * read_ptr;
    static char read_buf[MAXLINE];
    if(read_cnt <= 0) {
        again:
        if((read_cnt = read(fd,read_buf, sizeof(read_buf))) < 0) {
            if(errno == EINTR) { //EINTR系统调用被中断;
                goto again;
            } 
            return -1;
        } else if(read_cnt == 0){
            return 0;
        }
        read_ptr = read_buf;
    }
    read_cnt--;
    *ptr = *read_ptr++;
    return 1;
}
```

如果我们测量以下新老版本读一个2781行的文件(135816字节)所需时间就会发现，
老版本需要8.8秒，而新版本只需0.3秒，几乎所有的区别都由内核中所耗时间即系统时间引起，
老版本执行了135816次系统调用，而新版本仅进行了34次系统调用(135816除以MAXLINE是4096)。
不幸的是，在函数my_read中用静态变量来维护会跨越连续调用的状态信息，因而不再是可重入或线程安全的了；