#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j;

	for (i = 1; i <= 4; i++)
	{// 调整第二个for的判断条件
		for (j = 1; j < 2 * i; j++)
		{
			printf("%d", j);
		}
		printf("\n");
	}
	return 0;
}
