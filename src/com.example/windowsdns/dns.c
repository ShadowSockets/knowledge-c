#pragma comment(lib, "ws2_32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock.h>

#define MAX_BUFFER_SIZE 1024

void processDNSRequest(char* requestMsg,char* responseMsg){
    char* domainName ="example.com";
    char* ipAddress = "192.168.0.118";
    sprintf(responseMsg, "DNS响应：域名：%s，IP地址：%s", domainName, ipAddress);
}

int main(){
    WSADATA wsadata;
    if (WSAStartup(MAKEWORD(2,2), &wsadata) != 0) {
        fprintf(stderr,"Failed to initialize Winsock\n");
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET,SOCK_DGRAM,0);
    if(serverSocket == INVALID_SOCKET) {
        fprintf(stderr,"Failed to create server socket\n");
        WSACleanup();
        return 1;
    }

    struct sockaddr_in serverAddr,clientAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(53);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if(bind(serverSocket,(struct sockaddr *)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        fprintf(stderr,"Failed to bind server socket\n");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    printf("DNS Server started on port 53");

    char requestMessage[MAX_BUFFER_SIZE];
    char responseMessage[MAX_BUFFER_SIZE];

    while(1){
        int addrLen = sizeof(clientAddr);
        int bytesRead = recvfrom(serverSocket,requestMessage,MAX_BUFFER_SIZE,0,(struct sockaddr *)&clientAddr,&addrLen);
        if(bytesRead == SOCKET_ERROR) {
            fprintf(stderr,"Failed to receive DNS request\n");
            continue;
        }

        printf("收到DNS请求：%s\n",requestMessage);
        processDNSRequest(requestMessage,responseMessage);

        int bytesSent = sendto(serverSocket,responseMessage, strlen(responseMessage),0,(struct sockaddr *)&clientAddr,addrLen);
        if(bytesSent == SOCKET_ERROR) {
            fprintf(stderr,"Failed to send DNS response\n");
            continue;
        }
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}