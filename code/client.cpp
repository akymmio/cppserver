// 服务器端
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr; // ipv4结构体
    bzero(&serv_addr, sizeof(serv_addr));
    // 协议族
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // 转化为网络字节序的32位二进制整数
    serv_addr.sin_port = htons(8888);                   // 将主机字节序的 16 位短整型数据转换为网络字节序（大端字节序）的二进制数据

    connect(sockfd, (sockaddr *)&serv_addr, sizeof(serv_addr));
    return 0;
}