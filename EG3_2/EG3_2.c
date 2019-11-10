#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int i = 1;
    int sum = 0;

    while (i <= 100) // ;这里有一个多余的；
    {
        sum += i;
        i++; // 计数器没有进步
    }
    printf("sum=%d\n", sum);
    return 0;
}