#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int r1 = 0, i = 0;
    double r2 = 1.0;
    for (i = 1; i <= 100; i++)
    {
        if (i & 1)
            r2 *= i;
        else
            r1 += i;
    } // 精度取15
    printf("FOR     , 偶数相加：%d, 奇数相乘：%.15e\n", r1, r2);
    i = 0, r1 = 0, r2 = 1;
    while (i++ < 100)
    {
        if (i & 1)
            r2 *= i;
        else
            r1 += i;
    }
    printf("WHILE   , 偶数相加：%d, 奇数相乘：%.15e\n", r1, r2);
    i = 1, r1 = 0, r2 = 1;
    do
    {
        if (i & 1)
            r2 *= i;
        else
            r1 += i;
    } while (++i <= 100);
    printf("DO WHILE, 偶数相加：%d, 奇数相乘：%.15e\n", r1, r2);
    return 0;
}