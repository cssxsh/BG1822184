#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int c; // 用来接收字符的话int比char更好
    int _0_9 = 0, a_z = 0, A_Z = 0, other = 0;
    printf("请输入字符：\n");
    while ((c = getchar()) != EOF)
    {
        if (c > 'a' && c < 'z')
        {
            a_z++;
        }
        else if (c > 'A' && c < 'Z')
        {
            A_Z++;
        }
        else if (c > '0' && c < '9')
        {
            _0_9++;
        }
        else
        {
            other++;
        }
        if (c == 'q' || c == 'Q')
        {
            break;
        }
    }
    printf("数字：%d，小写字母：%d，大写字母：%d，其他：%d。",
           _0_9, a_z, A_Z, other);
    return 0;
}