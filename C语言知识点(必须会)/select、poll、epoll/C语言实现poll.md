###C语言实现poll，这是网上一个独立的例子，只是一个服务端，没有对应的客户端；
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

#define ARRAY_SIZE(x) (sizeof(x)/sizeof(x[0]))

int main() {

    int fd = socket(AF_INET, SOCK_STREAM, 0);

    int reuse_port = 1;
    setsockopt(fd, SOL_SOCKET, SO_REUSEPORT, &reuse_port, sizeof(int));

    //绑定地址
    struct sockaddr_in bind_address;
    memset(&bind_address, 0, sizeof(struct sockaddr_in));
    bind_address.sin_addr.s_addr = inet_addr("0.0.0.0");
    bind_address.sin_family = AF_INET;
    bind_address.sin_port = htons(8088);
    int code = bind(fd, (struct sockaddr *) &bind_address, sizeof(struct sockaddr_in));
    if (code == -1) {
        perror("bind error");
        close(fd);
        return -1;
    }
    //设置监听状态
    code = listen(fd, 1024);
    if (code == -1) {
        perror("listen error");
        close(fd);
        return -1;
    }

    /**
      struct pollfd {
         int fd;        //文件描述符
         short events;  //注册的事件
         short revents; //实际发生的事件，由内核填充
      };
       其中，fd成员指定文件描述；
       events成员告诉poll监听fd上的那些事件，它是一系列事件的按位或；
       revents成员则由内核修改，已通知应用程序fd上实际发生了哪些事件。
       poll支持的事件类型如表所示：
            POLLIN      数据（包括普通数据和优先数据）可读。
            POLLRDHUP   TCP连接被对方关闭，或者对方关闭了写操作，它由GNU引入。
            POLLOUT     数据（包括普通数据和优先数据）可写。
     */
    struct pollfd fds_array[1024];
    for (int i = 0; i < 1024; ++i) {
        fds_array[i].fd = -1;
    }

    fds_array[0].fd = fd;
    fds_array[0].events = POLLIN;
    int max_index = 0;
    while (1) {

//    int poll(struct pollfd* fds, nfds_t nfds, int timeout)
//    - fds     : 需要检测的文件描述符集合
//    - nfds    : 这是第一个参数数组中最后一个有效元素的下标+1
//    - timeout : 阻塞时长，0表示不阻塞，-1表示阻塞，当检测到需要检测的文件描述符发生变化时，接触阻塞，>0（n）阻塞时长n，单位为
//    返回值：
//       -1表示失败
//       >0（n）表示成功，表示检测到了n个文件描述符发生了变化
        int receive_num = poll(fds_array, max_index + 1, -1);
        if (receive_num == -1) {
            perror("poll error");
            break;
        } else if (receive_num == 0) {
            continue;
        } else {
            //一系列事件的按位与，就是表示这些事件都有
            if (fds_array[0].revents & POLLIN) {
                printf("accept\n");

//           SOCKET accept（int sockfd，struct sockaddr *addr，socklen_t *addrlen）;　
//           参数：
//　　        sockefd：套接字描述符，该套接字在listen（）后监听连接。
//　　        addr：（可选）指针。指向一个缓冲区，其中接收为通讯层所知的连接实体的地址。Addr参数的实际格式由套接口创建时所产生的地址族确定。
//　　        addrlen：（可选）指针。输入参数，配合addr一起使用，指向存有addr地址长度的整形数。
                int cfd = accept(fd, NULL, NULL);
                if (cfd == -1) {
                    perror("accept error");
                    continue;
                } else {
                    int find_index = -1;
                    for (int i = 0; i < ARRAY_SIZE(fds_array); ++i) {
                        if (fds_array[i].fd == -1) {
                            fds_array[i].fd = cfd;
                            fds_array[i].events = POLLIN;
                            find_index = i;
                            break;
                        }
                    }
                    if (find_index == -1) {
                        printf("client connect too many,refuse!");
                        continue;
                    }
                    if (find_index > max_index) {
                        max_index = find_index;
                    }
                }
            } else {
                //遍历读取每个连接数据
                for (int i = 1; i <= max_index; ++i) {
                    if (fds_array[i].fd == -1) {
                        continue;
                    }
                    if (fds_array[i].revents & POLLIN) {
                        char buf[1024];
                        size_t read_num = read(fds_array[i].fd, buf, 1024);
                        if (read_num < 0) {
                            perror("read error");
                            close(fds_array[i].fd);
                            fds_array[i].fd = -1;
                            continue;
                        } else if (read_num == 0) {
                            printf("close\n");
                            close(fds_array[i].fd);
                            fds_array[i].fd = -1;
                            continue;
                        } else {
                            write(fds_array[i].fd, buf, read_num);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
```



####################演示Poll的用法，Server端####################
```c
#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<assert.h>
 
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<poll.h>
#define SIZE 100
 
void Init_fd(struct pollfd *fds)      //初始化fds
{
	int i=0;     
	for(;i<SIZE;i++)
	{
		fds[i].fd=-1;
		fds[i].events=0;
		fds[i].revents=0;
	}
}
 
void Insert_fd(struct pollfd *fds,int fd,short event)    //向fds中插入fd
{
	int i=0;
	for(;i<SIZE;i++)
	{
		if(fds[i].fd==-1)
		{
			fds[i].fd=fd;
			fds[i].events=event;
			break;
		}
	}
}
 
void Delete_fd(struct pollfd *fds,int fd)       //删除fds中的某个fd
{
	int i=0;
	for(;i<SIZE;i++)
	{
		if(fds[i].fd==fd)
		{
			fds[i].fd=-1;
			fds[i].events=0;
			break;
		}
	}
}
 
int main()
{
	int sockfd=socket(AF_INET,SOCK_STREAM,0);       //网络的TCP连接
	assert(sockfd!=-1);
	struct sockaddr_in ser,cli;
	memset(&ser,0,sizeof(ser));
 
	ser.sin_family=AF_INET;
	ser.sin_port=htons(9000);
	ser.sin_addr.s_addr=inet_addr("127.0.0.1");
 
	int ret=bind(sockfd,(struct sockaddr*)(&ser),sizeof(ser));
	assert(ret!=-1);
	listen(sockfd,5);
 
	struct pollfd fds[SIZE];   //pollfd结构类型的数组
	Init_fd(fds);            //初始化fds
	Insert_fd(fds,sockfd,POLLIN);     //将sockfd插入到fds中  
 
	while(1)
	{
		int n=poll(fds,SIZE,-1);   //用poll找出fds中哪些文件描述符已经就绪，并返回就绪文件描述符的个数       
		if(n<=0)
		{
			printf("Error\n");
			continue;
		}
 
		int i=0;
		for(;i<SIZE;i++)          //遍历所有的文件描述符       
		{
			if(fds[i].fd!=-1)     
			{
				int fd=fds[i].fd;
				if(fds[i].revents & POLLIN)
				{
					if(fds[i].revents & POLLRDHUP)     //因为触发POLLRDHUP事件也必然会触发POLLIN事件，因此将POLLRDHUP事件放到POLLIN事件中处理
					{
						Delete_fd(fds,fd);
						close(fd);
					}
					else if(fd==sockfd)      //和select相似，如果fd=sockfd，那么表明操作应该是建立连接
					{
						int client=sizeof(cli);
						int c=accept(sockfd,(struct sockaddr*)(&cli),&client);
						if(c<=0)            //如果accept失败
						{
							printf("Error\n");
							continue;
						}
						else               //反之
						{
							Insert_fd(fds,c,POLLIN | POLLRDHUP);     //将c插入到fds中
						}
					}
					else                    //如果fd!=sockfd,那么表明应该是接受数据
					{
						char buff[128]={0};
						int n=recv(fd,buff,127,0);
						if(strcmp(buff,"end")==0)
						{
							break;
						}
						printf("%d:  %s\n",fd,buff);
						send(fd,"OK",2,0);
					}
				}
			}
		}
	}
}
```

####################演示Poll的用法，Client端####################
```c
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<assert.h>
 
int main()
{
	int sockfd=socket(PF_INET,SOCK_STREAM,0);
	assert(sockfd != -1);
	struct sockaddr_in ser,cli;
 
	ser.sin_family=AF_INET;
	ser.sin_port=htons(9000);
	ser.sin_addr.s_addr=inet_addr("127.0.0.1");
 
	connect(sockfd,(struct sockaddr*)(&ser),sizeof(ser));
	while(1)
	{
		printf("please input: ");
		fflush(stdout);
		char buff[128]={0};
		fgets(buff,128,stdin);
		buff[strlen(buff)-1] = '\0';
		
		//发送信息到服务端
		send(sockfd,buff,127,0);
		if(strcmp(buff,"end")==0)
		{
			break;
		}
		char recvbuff[128]={0};
		
		//接收服务端返回的信息
		recv(sockfd,recvbuff,127,0);
		printf("%s\n",recvbuff);
	}
	close(sockfd);
}
```