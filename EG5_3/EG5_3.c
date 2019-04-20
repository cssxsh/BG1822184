#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n = 5, sum = 0, temp1 = 0, temp2 = 0;
	int **arr = NULL;

	printf("���������Ĵ�С��\n");
	scanf("%d", &n);
	printf("���������\n");
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
		printf("���������ħ����\n");
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
				printf("���������ħ����\n");
				break;
			}
		}
		if (sum == temp1 && sum == temp2)
		{
			printf("���������ħ����\n");
		}
	}

	printf("����ṹ���£�\n");
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