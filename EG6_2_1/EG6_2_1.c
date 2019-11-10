#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double fact(int a);
int main(void)
{
    int n;
    printf("请输入N：");
    scanf("%d", &n);
    printf("%lf", fact(n));
    return 0;
}
double fact(int a)
{
    if (a == 0)
    {
        return 1.0;
    }
    return fact(a - 1) * a;
}