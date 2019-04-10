#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a;
	float b;

	//scanf参数应该是变量的地址
	scanf("%d%f", &a, &b);

	double c;
	scanf("%lf", &c);

	//输出的因该是变量的值，而不是变量的地址
	printf("a=%d,b=%f,c=%lf\n", a, b, c);
	return 0;
}