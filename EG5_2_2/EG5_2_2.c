#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define STU_NUM 40
#define Level 11

int main(void)
{
	int score[STU_NUM], count[Level];
	char temp[STU_NUM + 1];
	srand(1701420218);
	memset(count, 0, sizeof(int) * Level);
	// 通过随机数产生评价数据
	for (int i = 0; i < STU_NUM; i++)
	{
		score[i] = rand() % 10 + 1;
	}
	for (int i = 0; i < STU_NUM; i++)
	{
		count[score[i]]++;
	}
	printf("Grade\tCount\tHistogram\n");
	for (int i = 1; i < Level; i++)
	{
		memset(temp, '*', count[i]);
		temp[count[i]] = '\0';
		printf("%d\t%d\t%s\n", i, count[i], temp);
	}
	return 0;
}