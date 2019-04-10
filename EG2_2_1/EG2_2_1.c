#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int a = 5, b = 6;   /* 或 int  a=5, b=5 ;*/
	if (a == b)/*; 这里有一个多余的;, 构成了空语句，与下面的代码段断开*/
	{
		printf("a和b相等\n");
	}
	return 0;
}