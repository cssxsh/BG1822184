#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	// sum 未声明就使用
	float sum = 0.0;

	int a[5] = { 5, 4, 3, 2, 1 };
	int i;

	// 数组下标起始为0
	for (i = 0; i < 5; i++)
	{
		sum = sum + a[i];
	}
	// c 语言严格区分大小写 Sum 应为 sum
	printf("sum=%f\n", sum);

	return 0;
}