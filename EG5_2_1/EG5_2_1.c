#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(void)
{
    int n, *arr, max = INT_MIN, min = INT_MAX;
    double avg = 0.0;
    printf("请输入要产生的随机数的个数：");
    scanf("%d", &n);
    arr = malloc(sizeof(int) * n);

    srand(1701420218);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 11 + 10;
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
        avg += arr[i];
    }
    avg /= n;

    printf("最大值：%d，最小值：%d，平均值：%0.2lf。", max, min, avg);

    free(arr);
    return 0;
}