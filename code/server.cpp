#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <stdio.h>
int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    bind(sockfd, (sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, SOMAXCONN);
    // 监听socket端口，somaxconn最大监听队列长度

    // 接受客户端连接,需要保存客户端的socket地址信息
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    // 无符号整型数据类型，用于表示套接字地址结构体的长度
    bzero(&client_addr, sizeof(client_addr));
    int client_sockfd = accept(sockfd, (sockaddr *)&client_addr, &client_addr_len);
    printf("new client fd:%d! IP:%s Port:%d\n", client_sockfd, inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
}