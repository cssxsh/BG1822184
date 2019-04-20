#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 5;
	int **arr = NULL;
	int sum = 0;

	printf("请输入魔方的大小：");
	scanf("%d", &n);
	arr = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int *)malloc(n * sizeof(int));
		for (int j = 0; j < n; j++)
		{
			scanf("%d", arr[i] + j);
		}
	}

	for (int i = 0; i < n; i++)
	{
		sum += arr[i][i];
	}


	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}