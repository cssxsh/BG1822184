#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    char c, word = 0, isW = 0, temp;
    printf("Input words:");
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            break;
        }
        word += (isW != (temp = (c != ' '))) && temp;
        isW = temp;
    }
    printf("Count = %d", word);
    return 0;
}