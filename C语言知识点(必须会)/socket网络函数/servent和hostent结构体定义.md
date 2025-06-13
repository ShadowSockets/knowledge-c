#####################servent(server-entry)结构体###############################
```c
/* Description of data base entry for a single service.  */
struct servent
{
  char  *s_name;	    /* Official service name.  */   //表示的是服务名
  char  **s_aliases;    /* Alias list.  */              //表示的是服务别名列表
  int   s_port;			/* Port number.  */             //表示的是端口号
  char  *s_proto;		/* Protocol to use.  */         //使用的协议
};
```
以下是相关函数：
```c
struct servent *getservbyname(const char *name , const char *proto);
struct servent *getservbyport(int port , const char *proto);
struct servent *getservent(void);
//以上三个函数的返回值，如果成功则返回指针，出错则返回NULL；
void setservent(int stayopen);
void endservent(void);
```

###1)getserverbyname
服务是由地址的端口号部分表示的。每个服务由一个唯一的、熟知的端口号来提供。此函数可以将一个服务名字映射到一个端口号。
该函数会/etc/services中匹配使用protocol proto 的service name，如果proto为NULL,则任何protocol将会被匹配.
```c
#include <stdio.h>
#include <netdb.h>

int main() {
    struct servent *serv = NULL;
    serv = getservbyname("telnet", "tcp");
    if (serv != NULL) {
        printf("servent name: %s\n", serv->s_name);

        if (*serv->s_aliases != NULL) {  //*serv->s_aliases 意思是： *(serv->s_aliases) ,因为箭头符号优先级高
            printf("alias name: %s\n", *serv->s_aliases);
        }
        printf("port number: %d\n", serv->s_port);
        printf("proto to use: %s\n", serv->s_proto);
    }
    return 0;
}

//运行结果
$ ./test
servent name:   telnet
port number:    5888
proto to use:   tcp
```

###2)getservbyport
将一个端口号映射到一个服务名
```c
#include <stdio.h>
#include <netdb.h>
int main() {
      struct servent *serv = NULL;
      serv = getservbyport(5888, "tcp");
      if (serv != NULL) {
          printf("servent2 name: %s\n", serv->s_name);
          if (*(serv->s_aliases) != NULL) {
              printf("alias name: %s\n", *(serv->s_aliases));
          }
          printf("port number: %d\n", serv->s_port);
          printf("proto to use: %s\n", serv->s_proto);
      }
      return 0;
}
//执行结果：
servent2 name:  telnet
port number:    5888
proto to use:   tcp
```








###############################hostent(host-entry)结构体###############################
```c
/* Description of data base entry for a single host.  */
struct hostent
{
  char  *h_name;		/* Official name of host.  */   //正式主机名
  char  **h_aliases;	/* Alias list.  */              //主机别名
  int   h_addrtype;		/* Host address type.  */       //主机IP地址类型：IPV4-AF_INET
  int   h_length;		/* Length of address.  */       //主机IP地址字节长度，对于IPv4是四字节，即32位
  char  **h_addr_list;	/* List of addresses from name server.  */ //主机的IP地址列表
  #define h_addr h_addr_list[0] /* Address, for backward compatibility.(为了向后兼容)*/ //保存的是IP地址
};
```
应用示例：
```c
#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define HOSTNAME "www.baidu.com"

int main(int argc, char *argv[]) {
    struct hostent *hptr;
    char **pptr;
    char str[32] = {0};

    if ((hptr = gethostbyname(HOSTNAME)) == NULL) {
        printf("gethostbyname error: %s\n", HOSTNAME);
        return 0;
    }
    printf("official hostname:%s\n", hptr->h_name); //主机规范名

    for (pptr = hptr->h_aliases; *pptr != NULL; pptr++) { //将主机别名打印出来
        printf("alias: %s\n", *pptr);
    }

    switch (hptr->h_addrtype) { //根据地址类型，将地址打印出来
        case AF_INET:
        case AF_INET6:
            pptr = hptr->h_addr_list;
            for (; *pptr != NULL; pptr++) { //将得到的所有地址打印出来
                //inet_ntop: 将网络字节序的二进制转换为文本字符串的格式[将IP地址在“点分十进制”和“二进制整数”之间转换]
                //数中p和n分别代表：表达（presentation)和数值（numeric)
                printf("address: %s\n", inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
                printf("first address: %s\n", inet_ntop(hptr->h_addrtype, hptr->h_addr_list, str, sizeof(str)));
            }
            break;
        default:
            printf("unknown address type\n");
            break;
    }
    return 0;
}
///运行结果：
official hostname:www.a.shifen.com
alias: www.baidu.com
address: 36.152.44.96
first address: 176.215.169.161
address: 36.152.44.95
first address: 176.215.169.161
```