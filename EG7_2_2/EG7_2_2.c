#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 参数应该是数组或者指针形式
void link(char *s, char *t, char *r);
int main(void)
{
    char s[128], t[128], r[256];
    printf("请输入第一个字符串：\n");
    gets(s);
    printf("请输入第二个字符串：\n");
    gets(t);
    link(s, t, r);
    printf("连接后的字符串：\n%s", r);
    return 0;
}
void link(char *s, char *t, char *link) //; 多余的分号
{
    char *k = link;
    char temp;
    while (*s != '\0' && *t != '\0')
    {
        if (*s < *t)
        {
            temp = *s;
            s++;
        }
        else
        {
            temp = *t;
            t++;
        }
        *link = temp;
        link++;
    }
    while (*s != '\0')
    {
        *link = *s;
        link++;
        s++;
    }
    while (*t != '\0')
    {
        *link = *t;
        link++;
        t++;
    }
    *link = '\0';
}