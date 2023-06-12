
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>

int main()
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0); // sockfd(fild descriptor)
    struct sockaddr_in serv_addr;                 // sockaddr_in是一个用于IPv4地址的结构体,in_addr是一个用于存储IPv4地址的数据结构。
    bzero(&serv_addr, sizeof(serv_addr));         // bzero()所有成员都清零（初始化为0）
    // 设置地址族、IP地址和端口：
    serv_addr.sin_family = AF_INET; // 成员变量sin_family、sin_addr.s_addr和sin_port分别表示地址族、服务器IP地址和端口号。
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8888);

    // bind(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)); 客户端不进行bind操作

    connect(sockfd, (sockaddr *)&serv_addr, sizeof(serv_addr));

    return 0;
}