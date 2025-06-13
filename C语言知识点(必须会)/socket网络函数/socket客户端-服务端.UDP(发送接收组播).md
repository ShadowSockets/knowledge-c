###多播组结构体介绍
```text
    //组播(或叫多播)的结构体的定义：
//    struct ip_mreq
//    {
//        struct in_addr imr_multiaddr; //一个多播组的IP地址(要和发送方使用的一样，才能接收到该组信息)
//        组播地址解释：
//          在IPv4中，它历史上被叫做D类地址，一种类型的IP地址，它的范围从224.0.0.0到239.255.255.255，或，等同的，在224.0.0.0/4。
//          在IPv6，多播地址都有前缀ff00::/8。但是注意，224.0.0.0被保留，不能赋给任何多播组。
//        struct in_addr imr_interface; //加入的客服端主机IP地址   //本地某一网络设备接口的IP地址。
//    }
//    struct ip_mreq my_mreq;
//    memset(&my_mreq, 0, sizeof(my_mreq));
//    my_mreq.imr_multiaddr.s_addr = inet_addr("224.0.0.2"); //要和发送端一样
//    my_mreq.imr_interface.s_addr = INADDR_ANY;
//    if(-1 == setsockopt(serverSocket,IPPROTO_IP,IP_ADD_MEMBERSHIP,&my_mreq, sizeof(my_mreq))){
//        perror("setsockopt error");
//    }
```


######UDP服务端(接收组播示例)
```c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define GROUP_PORT 8080

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


    //接收组播信息第一步：设置当前主机加入组播。
    struct ip_mreq my_mreq;
    memset(&my_mreq,0, sizeof(my_mreq));
    my_mreq.imr_multiaddr.s_addr = inet_addr("224.0.0.2");//(组播地址)要和发送端一样
    my_mreq.imr_interface.s_addr = INADDR_ANY;
    //把本机加入组播地址，即本机网卡作为组播成员，只有加入组才能收到组播消息。
    if(-1 == setsockopt(socket_desc, IPPROTO_IP, IP_ADD_MEMBERSHIP, &my_mreq, sizeof(my_mreq))){
        printf("setsockopt error");
        exit(1);
    }
    

    //设置组播地址和端口：
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("224.0.0.2");//(组播地址)要和发送端一样
    server_addr.sin_port = htons(GROUP_PORT);
    //绑定组播地址和端口：
    if (bind(socket_desc, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
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


######UDP客户端(发送组播示例)
```c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define GROUP_PORT 8080

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

    
    //Get input from the user;
    printf("Enter message:\n");
    scanf("%s", client_message);


    //发送组播第一步：建立组播套接字地址。
    struct sockaddr_in groupaddr;
    groupaddr.sin_family = AF_INET;
    groupaddr.sin_addr.s_addr = inet_addr("224.0.0.2"); //指定一个组播地址
    //组播地址解释：在IPv4中，它历史上被叫做D类地址，一种类型的IP地址，它的范围从224.0.0.0到239.255.255.255，或，等同的，在224.0.0.0/4。
    //在IPv6，多播地址都有前缀ff00::/8。但是注意，224.0.0.0被保留，不能赋给任何多播组。
    groupaddr.sin_port = htons(GROUP_PORT);
    

    //发送组播第二步：向组播地址发送数据。
    printf("send message:\n");
    if (sendto(socket_desc, client_message, strlen(client_message), 0,
    (struct sockaddr *) &groupaddr, sizeof(groupaddr)) < 0) {
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