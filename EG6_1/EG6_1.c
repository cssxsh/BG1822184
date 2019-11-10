#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// 函数参数应该逐个声明
int max(int a, int b) //; 这里有一个多余的；
{                     // 变量使用前要声明，并且最好不要与已有函数或者变量同名
    int result;
    if (a > b)
        result = a;
    else
        result = b;

    return result;
}
void main()
{ // 变量与函数重名
    int Max, x, y;

    printf("输入两个整数，用空格隔开：");
    scanf("%d%d", &x, &y);
    Max = max(x, y);
    printf("max=%d\n", Max);
}