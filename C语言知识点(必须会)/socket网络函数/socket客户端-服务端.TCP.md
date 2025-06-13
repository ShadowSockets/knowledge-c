######TCP服务端
```text
作为服务器，你要绑定[bind]到本地的IP地址上进行监听[listen]，但是你的机器可能有多块网卡，
也就有多个IP地址，这时候你要选择绑定在哪个IP上面，如果指定为INADDR_ANY，那么系统将绑定默认的网卡【即IP地址】。
就比方说我这里本机的ip地址包括：
192.168.197.129
127.0.0.1
0.0.0.0

作为客户端，你要连接【connect】到远端的服务器，也是要指定远端服务器的(ip,port)对。
当然，在这种情况下，不可能将IP地址指定为INADDR_ANY，系统会疯掉的。
```
```c
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>

#define PORT 1500//端口号 
#define BACKLOG 5/*最大监听数*/ 

int main(){
    int sockfd,new_fd;  /*socket句柄和建立连接后的句柄*/
    struct sockaddr_in my_addr; /*本方地址信息结构体，下面有具体的属性赋值*/
    struct sockaddr_in their_addr;  /*对方地址信息*/
    int sin_size;

    sockfd=socket(AF_INET,SOCK_STREAM,0);   //建立socket 
    /**
     * 指定协议。常用的协议有，IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC等，
     * 它们分别对应TCP传输协议、UDP传输协议、STCP传输协议、TIPC传输协议
     * 当protocol(最后一个参数)为0时，会自动选择type类型对应的默认协议。
     */
    
    if(sockfd == -1){
        printf("socket failed:%d",errno);
        return -1;
    }
    my_addr.sin_family = AF_INET;   /*sin_family指代协议族，在socket编程中只能是AF_INET*/
    my_addr.sin_port = htons(PORT); /*端口号*/
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY); //看上面解释
    bzero(&(my_addr.sin_zero),8);   /*将其他属性置0*/
    if(bind(sockfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr))<0){//绑定地址结构体和socket
        printf("bind error");
        return -1;
    }
    listen(sockfd,BACKLOG);//开启监听 ，第二个参数是最大监听数 
    while(1){
        sin_size = sizeof(struct sockaddr_in);
        //在这里阻塞知道接收到消息，参数分别是socket句柄，接收到的地址信息，以及大小
        new_fd = accept(sockfd,(struct sockaddr*)&their_addr,&sin_size);  
        if(new_fd == -1){
            printf("receive failed");
        } else{
            printf("receive success");
            send(new_fd,"Hello World!",12,0); //发送内容，参数分别是连接句柄，内容，大小，其他信息（设为0即可） 
        }
    }
    return 0;
} 
```


######TCP客户端
```c
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/wait.h>
#include <arpa/inet.h>

#define DEST_PORT 1500      //目标地址端口号 
#define DEST_IP "127.0.0.1" /*目标地址IP，这里设为本机*/ 
#define MAX_DATA 100        //接收到的数据最大程度 

int main(){
    int sockfd,new_fd;          /*socket句柄和接受到连接后的句柄 */
    struct sockaddr_in dest_addr;/*目标地址信息*/
    char buf[MAX_DATA];         //储存接收数据 

    sockfd=socket(AF_INET,SOCK_STREAM,0); /*建立socket*/
    if(sockfd==-1){
        printf("socket failed:%d",errno);
    }
    
    //参数意义见上面服务器端 
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(DEST_PORT);
    dest_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    bzero(&(dest_addr.sin_zero),8);
    
    if(connect(sockfd,(struct sockaddr*)&dest_addr,sizeof(struct sockaddr))==-1){ //连接方法，传入句柄，目标地址和大小 
        printf("connect failed:%d",errno); //失败时可以打印errno 
    } else{
        printf("connect success");
        recv(sockfd,buf,MAX_DATA,0); //将接收数据打入buf，参数分别是句柄，储存处，最大长度，其他信息（设为0即可）。 
        printf("Received:%s",buf);
    }
    close(sockfd); //关闭socket 
    return 0;
} 
```