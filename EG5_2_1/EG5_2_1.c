#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, *arr, max = INT_MIN, min = INT_MAX;
	double avg = 0.0;
	printf("������Ҫ������������ĸ�����");
	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);

	srand(1701420218);
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 11 + 10;
		max = arr[i] > max ? arr[i] : max;
		min = arr[i] < min ? arr[i] : min;
		avg += arr[i];
	}
	avg /= n;

	printf("���ֵ��%d����Сֵ��%d��ƽ��ֵ��%0.2lf��", max, min, avg);

	free(arr);
	return 0;
}