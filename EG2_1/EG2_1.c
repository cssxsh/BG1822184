#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int year;

	printf("请输入年份：");
	scanf("%d", &year);
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("闰年！");
	}
	else
	{
		printf("不是闰年！");
	}
	return 0;
}
