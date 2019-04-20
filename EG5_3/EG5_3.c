#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 5, sum = 0, temp1 = 0, temp2 = 0;
	int **arr = NULL;

	printf("请输入矩阵的大小：\n");
	scanf("%d", &n);
	printf("请输入矩阵：\n");
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
		temp1 += arr[i][n - 1];
	}
	if (sum != temp1)
	{
		printf("这个矩阵不是魔方！\n");
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			temp1 = temp2 = 0;
			for (int j = 0; j < n; j++)
			{
				temp1 += arr[i][j];
				temp2 += arr[j][i];
			}
			if (sum != temp1 || sum != temp2)
			{
				printf("这个矩阵不是魔方！\n");
				break;
			}
		}
		if (sum == temp1 && sum == temp2)
		{
			printf("这个矩阵是魔方！\n");
		}
	}

	printf("矩阵结构如下：\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < n; i++)
	{
		free(arr[i]);
	}
	free(arr);
	return 0;
}


/*
17 24 1 8 15
23 5 7 14 16
4 6 13 20 22
10 12 19 21 3
11 18 25 2 9

*/