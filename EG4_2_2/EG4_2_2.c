#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int x, i = 1, j = 1, k = 1;

	printf("��������");
	if (scanf("%d", &x))
	{
		if (x % 10 || x > 100 || x < 0)
		{
			printf("�������");
			return 2;
		}// ��ѭ���ķ�ʽ�����������ΰ�5��2��1Ԫ��࿪ʼ
		for (k = (x - 8) / 5 + 1; k > 0; k--)
		{
			for (j = (x - 5 * k - 1) / 2; j > 0; j--)
			{
				i = x - 5 * k - 2 * j;
				if (i)
				{
					printf("1*%d + 2*%d + 5*%d = %d\n", i, j, k, x);
					return 0;
				}
			}
		}
	}
	else
	{
		printf("�������");
		return 1;
	}
	return 0;
}