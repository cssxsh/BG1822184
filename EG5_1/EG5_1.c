#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	// sum δ������ʹ��
	float sum = 0.0;

	int a[5] = { 5, 4, 3, 2, 1 };
	int i;

	// �����±���ʼΪ0
	for (i = 0; i < 5; i++)
	{
		sum = sum + a[i];
	}
	// c �����ϸ����ִ�Сд Sum ӦΪ sum
	printf("sum=%f\n", sum);

	return 0;
}