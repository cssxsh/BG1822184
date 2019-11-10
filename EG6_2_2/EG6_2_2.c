#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int AddTest(int a, int b);
int main(void)
{
    int grade = 0, errnum = 0;
    int a, b;
    srand(1701420218);

    for (int i = 0; i < 10; i++)
    {
        a = rand() % 10 + 1;
        b = rand() % 10 + 1;
        printf("%d + %d = ", a, b);
        if (AddTest(a, b))
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
int AddTest(int a, int b)
{
    int sum;
    scanf("%d", &sum);
    return (a + b == sum);
}