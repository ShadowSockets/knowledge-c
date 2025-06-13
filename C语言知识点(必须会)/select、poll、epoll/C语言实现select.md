```text
函数原型：
int select(nfds, readfds, writefds, exceptfds, timeout)

参数类型：
int     nfds;
fd_set  *readfds, *writefds, *exceptfds;
struct  timeval *timeout;

参数介绍：
nfds：select监视的文件句柄数，视进程中打开的文件数而定,一般设为你要监视各文件中的最大文件号加一。
（注：nfds并非一定表示监视的文件句柄数。官方文档仅指出：
nfds is the highest-numbered file descriptor in any of the three sets, plus 1. 
(可在linux环境中通过man select命令查得)）

readfds：    select监视的可读文件句柄集合。
writefds:    select监视的可写文件句柄集合。
exceptfds：  select监视的异常文件句柄集合。
timeout：    本次select()的超时结束时间。（见/usr/sys/select.h，可精确至百万分之一秒！）


当readfds或writefds中映象的文件可读或可写或超时，本次select()
就结束返回。程序员利用一组系统提供的宏在select()结束时便可判
断哪一文件可读或可写，对Socket编程特别有用的就是readfds。
```


###C语言实现select
```c
#include <stdio.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main() {
    return 0;
}


void do_proxy (int usersockfd)
{
    int isosockfd;
    fd_set rdfdset;
    int connstat;
    int iolen;
    char buf[2048];
    /* open a socket to connect to the isolated host */
    if ((isosockfd = socket(AF_INET,SOCK_STREAM,0)) < 0)
        errorout("failed to create socket to host");
    /* attempt a connection */
    connstat = connect(isosockfd,(struct sockaddr *) &hostaddr, sizeof(hostaddr));
    switch (connstat) {
        case 0:
            break;
        case ETIMEDOUT:
        case ECONNREFUSED:
        case ENETUNREACH:
            strcpy(buf,sys_myerrlist[errno]);
            strcat(buf,"\r\n");
            write(usersockfd, buf, strlen(buf));
            close(usersockfd);
            exit(1);
            /* die peacefully if we can't establish a connection */
            break;
        default:
            errorout("failed to connect to host");
    }
    
    /* now we're connected, serve fall into the data echo loop */
    while (1) {
        /* Select for readability on either of our two sockets */
        FD_ZERO(&rdfdset);
        FD_SET(usersockfd,&rdfdset);
        FD_SET(isosockfd,&rdfdset);
        if (select(FD_SETSIZE,&rdfdset,NULL,NULL,NULL) < 0) {
            errorout("select failed");
        }
        /* is the client sending data? */
        if (FD_ISSET(usersockfd,&rdfdset)) {
            if ((iolen = read(usersockfd,buf,sizeof(buf))) <= 0) {
                break; /* zero length means the client disconnected */
            }
            write(isosockfd,buf,iolen); /* copy to host -- blocking semantics */
        }
    
        /* is the host sending data? */
        if(FD_ISSET(isosockfd,&rdfdset)) {
            if((iolen = read(isosockfd,buf,sizeof(buf))) <= 0) {
                break; /* zero length means the host disconnected */
            }
            write(usersockfd,buf,iolen); /* copy to client -- blocking semantics */
        }
    }
    /* we're done with the sockets */
    close(isosockfd);
    close(usersockfd);
}


//displays an error message on the console and kills the current process.
void errorout (char *msg)
{
    FILE *console;
    console = fopen("/dev/console","a");
    fprintf(console,"proxyd: %s\r\n",msg);
    fclose(console);
    exit(1);
}
```