#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a = 6;        /* 或 int  a=6*/
	int b = 6;
	if (a == b)
	{// 需要{}把下面两条语句合并成代码块
		a++;
		b++;
	}
	printf("a=%d,b=%d", a, b);
	return 0;
}