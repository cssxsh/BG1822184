#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

int main(void)
{
	double question = -45.35, answer;

	answer = fabs(question);
	printf("数 %.2f 的绝对值是 %.2f\n", question, answer);
	return 0;
}