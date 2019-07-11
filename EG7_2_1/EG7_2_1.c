#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const char OP[4] = { '+', '-', '*', '/' };
int CalcTest(int a, int b, int op);
int main(int argc, char **argv)
{
	int a, b, op;
	sscanf(argv[1], "%d", &a);
	op = argv[2][0];
	sscanf(argv[3], "%d", &b);
	printf("%s %s %s = %d", argv[1], argv[2], argv[3], CalcTest(a, b, op));
	return 0;
}
int CalcTest(int a, int b, int op)
{
	int result;
	switch (op)
	{
	case '+':
		return (result = a + b);
		break;
	case '-':
		return (result = a - b );
		break;
	case '*':
		return (result = a * b );
		break;
	case '/':
		return (result = a / b);
		break;
	default:
		break;
	}
	return 0;
}