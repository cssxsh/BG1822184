#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 参数应该是数组或者指针形式
void mystrc(char *s, char *t);
int main(void)
{
    char s[80], t[80];
    gets(s);
    gets(t);
    mystrc(s, t);
    puts(t);
    return 0;
}
void mystrc(char *s, char *t) //; 多余的分号
{
    while (*t != '\0')
        t++;
    while (*s != '\0')
    {
        *t = *s;
        t++;
        s++;
    }
    *t = '\0';
}
