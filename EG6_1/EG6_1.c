#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ��������Ӧ���������
int max(int a, int b)//; ������һ������ģ�
{	// ����ʹ��ǰҪ������������ò�Ҫ�����к������߱���ͬ��
	int result;
	if (a > b)
		result = a;
	else
		result = b;

	return result;
}
void main()
{	// �����뺯������
	int  Max, x, y;

	printf("���������������ÿո������");
	scanf("%d%d", &x, &y);
	Max = max(x, y);
	printf("max=%d\n", Max);
}