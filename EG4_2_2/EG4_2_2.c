#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int x, i = 1, j = 1, k = 1;

    printf("请输入面额：");
    if (scanf("%d", &x))
    {
        if (x % 10 || x > 100 || x < 0)
        {
            printf("输入错误！");
            return 2;
        } // 将循环的方式倒过来按依次按5，2，1元最多开始
        for (k = (x - 8) / 5 + 1; k > 0; k--)
        {
            for (j = (x - 5 * k - 1) / 2; j > 0; j--)
            {
                i = x - 5 * k - 2 * j;
                if (i)
                {
                    printf("1*%d + 2*%d + 5*%d = %d\n", i, j, k, x);
                    return 0;
                }
            }
        }
    }
    else
    {
        printf("输入错误！");
        return 1;
    }
    return 0;
}