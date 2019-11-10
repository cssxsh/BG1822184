#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main(void)
{
	double a, b, c;
	char op;
printf("#这是一个简单的计算器#\n");
	printf("请按格式[操作数1  运算符op  操作数2]输入数据：\n");
	scanf("%lf %c%lf",  &a, &op, &b);
	switch (op)
	{
	case '+':
		c = a + b;
		break;
	case '-':
		c = a - b;
		break;
	case '*':
		c = a * b;
		break;
	case '/':
		if (fabs(b) <= 1e-7)
		{
			printf("零不能做除数！！！");
			return 0;
		}
		c = a / b;
		break;
	}
	printf("%lf%c%lf=%lf", a, op, b, c);
	return 0;
}