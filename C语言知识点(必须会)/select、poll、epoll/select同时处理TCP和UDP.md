###setsockopt函数值说明
```text
SO_REUSEADDR和SO_REUSEPORT

SO_REUSEADDR提供如下四个功能：
    SO_REUSEADDR允许启动一个监听服务器并捆绑其众所周知端口，即使以前建立的将此端口用做他们的本地端口的连接仍存在。这通常是重启监听服务器时出现，若不设置此选项，则bind时将出错。
    SO_REUSEADDR允许在同一端口上启动同一服务器的多个实例，只要每个实例捆绑一个不同的本地IP地址即可。对于TCP，我们根本不可能启动捆绑相同IP地址和相同端口号的多个服务器。
    SO_REUSEADDR允许单个进程捆绑同一端口到多个套接口上，只要每个捆绑指定不同的本地IP地址即可。这一般不用于TCP服务器。
    SO_REUSEADDR允许完全重复的捆绑：当一个IP地址和端口绑定到某个套接口上时，还允许此IP地址和端口捆绑到另一个套接口上。一般来说，这个特性仅在支持多播的系统上才有，而且只对UDP套接口而言（TCP不支持多播）。

SO_REUSEPORT选项有如下语义：
    此选项允许完全重复捆绑，但仅在想捆绑相同IP地址和端口的套接口都指定了此套接口选项才行。
    如果被捆绑的IP地址是一个多播地址，则SO_REUSEADDR和SO_REUSEPORT等效。
```


###select同时处理TCP和UDP程序示例(来自Unix网路编程卷1)
```c
#include <arpa/inet.h>
#include <string.h>
#include <stdio.h>
#include <poll.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE 200
#define SERV_PORT 8080
#define SA struct sockaddr

int max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}


//处理请求
void process_request(int fd) {
}

void sig_child(int signal){
    int pid;
    int status;
    while ((pid = wait3(&status,WNOHANG,NULL)) >0){
        printf("child %d terminated \n",pid);
    }
}

int main() {
    int listenfd, connfd, udpfd, nready, maxfdp1;
    char mesg[MAX_LINE];
    pid_t childpid;
    fd_set rset;
    ssize_t n;
    socklen_t len;
    const int on = 1;
    struct sockaddr_in cliaddr, servaddr;
    
    //create listening TCP socket
    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));
    bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
    listen(listenfd, 5);

    //create UDP socket
    udpfd = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);
    bind(udpfd, (SA *) &servaddr, sizeof(servaddr));

    signal(SIGCHLD, sig_child); //must call waitpid();
    FD_ZERO(&rset);
    maxfdp1 = max(listenfd, udpfd) + 1;

    for (;;) {
        FD_SET(listenfd, &rset);
        FD_SET(udpfd, &rset);
        if ((nready = select(maxfdp1, &rset, NULL, NULL, NULL)) < 0) {
            if (errno == EINTR) {
                continue; //back to for()
            }
            printf("select create error!\n");
            exit(1);
        }

        if (FD_ISSET(listenfd, &rset)) {
            len = sizeof(cliaddr);
            connfd = accept(listenfd, (SA *) &cliaddr, &len);
            if ((childpid = fork()) == 0) { //child process
                close(listenfd); // close listening socket
                process_request(connfd); //process the request
                exit(0);
            }
            close(connfd); //parent close connected socket
        }

        if (FD_ISSET(udpfd, &rset)) {
            len = sizeof(cliaddr);
            n = recvfrom(udpfd, mesg, MAX_LINE, 0, (SA *) &cliaddr, &len);
            sendto(udpfd, mesg, n, 0, (SA *) &cliaddr, len);
        }
    }

    return 0;
}
```