#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

const char OP[4] = {'+', '-', '*', '/'};
int CalcTest(int a, int b, int op);
int main(void)
{
    int grade = 0, errnum = 0;
    int a, b, op;
    srand(1701420218);

    for (int i = 0; i < 10; i++)
    {
        a = rand() % 10 + 1;
        op = OP[rand() % 4];
        b = rand() % 10 + 1;
        printf("%d %c %d = ", a, op, b);
        if (CalcTest(a, b, op))
        {
            printf("Right!\n");
            grade += 10;
        }
        else
        {
            printf("Not correct!\n");
            errnum += 1;
        }
    }
    printf("Grade: %d, ErrNum: %d", grade, errnum);

    return 0;
}
int CalcTest(int a, int b, int op)
{
    int result;
    scanf("%d", &result);
    switch (op)
    {
    case '+':
        return (a + b == result);
        break;
    case '-':
        return (a - b == result);
        break;
    case '*':
        return (a * b == result);
        break;
    case '/':
        return (a / b == result);
        break;
    default:
        break;
    }
    return 0;
}