######UDP服务端
```c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 2000
#define IP "127.0.0.1"

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
    
    
    //Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(IP);
    
    //Bind to the port and IP:
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
    (struct sockaddr *) &client_addr, client_struct_length) < 0) {
        printf("Can`t send\n");
        return -1;
    }
    
    //Close the socket;
    close(socket_desc);
    
    return 0;
}
```


######UDP客户端
```c

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define DEST_PORT 2000
#define DEST_IP "127.0.0.1"

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
    
    //Set port and IP:
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEST_PORT);
    server_addr.sin_addr.s_addr = inet_addr(DEST_IP);
    
    //Get input from the user;
    printf("Enter message:");
    scanf("%s", client_message);
    
    //Send the message to server;
    if (sendto(socket_desc, client_message, strlen(client_message), 0,
    (struct sockaddr *) &server_addr, server_struct_length) < 0) {
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