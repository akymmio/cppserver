#include <util.h>
#include <stdio.h>
#include <stdlib.h>
// 封装错误处理
void err(bool condition, const char *err_msg)
{
    if (condition)
    {
        perror(err_msg);    // 输出错误信息
        exit(EXIT_FAILURE); // 退出程序，返回非零值
    }
}