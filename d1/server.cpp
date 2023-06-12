#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in serv_addr;
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    bind(sockfd, (sockaddr *)&serv_addr, sizeof(serv_addr));
    // 将socket地址与文件描述符绑定

    listen(sockfd, SOMAXCONN); // 最大监听队列长度

    // 客户端连接
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_len = sizeof(clnt_addr);
    bzero(&clnt_addr, sizeof(clnt_addr));

    int clnt_sockfd = accept(sockfd, (sockaddr *)&clnt_addr, &clnt_addr_len);
    // 调用accept函数之前，我们需要先通过调用bind和listen函数将服务器的本地地址绑定到socket上，
    // 接受客户端的连接请求并返回一个新的socket文件描述符
    // 保存客户端的地址信息
    printf("new client fd %d! IP: %s Port: %d\n", clnt_sockfd, inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));
    return 0;
}