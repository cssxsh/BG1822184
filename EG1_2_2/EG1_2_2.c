#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a, b;
	int sum;

	scanf("%d%d", &a, &b);
	// sum的计算应该在scanf赋值之后
	sum = a + b;

	printf("sum=%d\n", sum);
}