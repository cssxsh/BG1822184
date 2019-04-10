#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	double a, b, c, average;

	scanf("%lf%lf%lf", &a, &b, &c);
	average = (a + b + c) / 3.0;
	printf("(a+b+c)/3=%0.2lf", average);
	return 0;
}