#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int i;
    int sum = 0; // 和的初值很重要

    for (i = 1; i <= 100; i++)
    {
        sum += i;
    }
    printf("sum=%d\n", sum);
    return 0;
}