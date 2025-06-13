######UDP服务端(接收广播示例)
```c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BROADCAST_PORT 8080

int main(void) {

    int socket_desc;
    struct sockaddr_in server_addr, client_addr;
    char server_message[2000], client_message[2000];
    unsigned int client_struct_length = sizeof(client_addr);
    
    //Clean buffers:
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    
    //Creat UDP socket:
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    /**
     * 指定协议。常用的协议有，IPPROTO_TCP、IPPTOTO_UDP、IPPROTO_SCTP、IPPROTO_TIPC等，
     * 它们分别对应TCP传输协议、UDP传输协议、STCP传输协议、TIPC传输协议
     * 当protocol(最后一个参数)为0时，会自动选择type类型对应的默认协议。
     */
    if (socket_desc < 0) {
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket create successfully\n");
    
    
    //接收广播第一步：建立广播地址
    struct sockaddr_in broadcastaddr;
    broadcastaddr.sin_family = AF_INET;
    broadcastaddr.sin_addr.s_addr = inet_addr("192.168.1.255"); //本机IP对应的广播地址，也可以通过ifconfig命令查看广播地址
    // 例如：当前主机IP为：192.168.1.146，那么他的广播地址就是：192.168.1.255
    broadcastaddr.sin_port = htons(BROADCAST_PORT);
    
    
    //接收广播第二步：绑定广播地址，准备接收广播信息。
    //Bind to the port and IP:
    if (bind(socket_desc, (struct sockaddr *) &broadcastaddr, sizeof(broadcastaddr)) < 0) {
        printf("Could n`t bind to the port\n");
        return -1;
    }
    printf("Done with binding\n");
    printf("Listening for incoming message...\n\n");
    
    //Receive client`s message: 当接收到客户端的UDP请求时，会把客户端信息存入这些客户端参数变量中.
    if (recvfrom(socket_desc, client_message, sizeof(client_message), 0,
    (struct sockaddr *) &client_addr, &client_struct_length) < 0) {
        printf("Could n`t receive\n");
        return -1;
    }
    
    //inet_ntoa()是编程语言，功能是将网络地址转换成“.”点隔的字符串格式。
    printf("Received message from IP: %s and port: %i\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
    printf("Msg from client: %s\n", client_message);
    
    
    //Respond to client
    strcpy(server_message, client_message);
    if (sendto(socket_desc, server_message, strlen(server_message), 0,
    (struct sockaddr *) &client_addr, sizeof(client_addr)) < 0) {
        printf("Can`t send\n");
        return -1;
    }
    
    //Close the socket;
    close(socket_desc);
    return 0;
}
```


######UDP客户端(发送广播示例)
```c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define BROADCAST_PORT 8080

int main() {

    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000];
    unsigned int server_struct_length = sizeof(server_addr);
    
    //Clean buffers;
    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));
    
    //Create socket
    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (socket_desc < 0) {
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");


    //发送广播第一步：设置发送广播
    int on = 1;
    if(setsockopt(socket_desc,SOL_SOCKET,SO_BROADCAST,&on,sizeof(on)) < 0) {
        printf("Error set broadcast\n");
        exit(1);
    }
    
    
    //Get input from the user;
    printf("Enter message:");
    scanf("%s", client_message);


    //发送广播第二步：建立广播套接字地址
    struct sockaddr_in broadcastaddr;
    broadcastaddr.sin_family = AF_INET;
    broadcastaddr.sin_addr.s_addr = inet_addr("192.168.1.255"); //本机IP对应的广播地址，也可以通过ifconfig命令查看广播地址
    // 例如：当前主机IP为：192.168.1.146，那么他的广播地址就是：192.168.1.255
    broadcastaddr.sin_port = htons(BROADCAST_PORT);
    

    ///发送广播第三步：向广播地址发送数据
    //Send the message to server; 
    if (sendto(socket_desc, client_message, strlen(client_message), 0,
    (struct sockaddr *) &broadcastaddr, sizeof(broadcastaddr)) < 0) {
        printf("Unable to send message\n");
        return -1;
    }
    
    //Receive the server`s response:
    if(recvfrom(socket_desc,server_message, sizeof(server_message),0,
    (struct sockaddr *)&server_addr,&server_struct_length) < 0){
        printf("Error while receiving server`s msg\n");
        return -1;
    }
    printf("Server`s response: %s\n",server_message);
    
    //Close the socket
    close(socket_desc);
    return 0;
}
```