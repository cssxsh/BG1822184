#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
    int n = 0, no = 0;
    char c;
    float temp, sum = 0;
    printf("请输入学生的成绩：\n");
    while (1)
    {
        if (scanf("%f", &temp))
        {
            if (temp < 0.0)
                break;
            if (temp < 60.0)
                no++;
            if (temp < 100.0)
            {
                sum += temp;
                n++;
            }
        }
        else
        { //清空stdin缓存区
            scanf(" %c", &c);
            scanf("%*[^\n]*c");
            printf("\n！错误“%c...”出现，请重新输入！\n", c);
        }
    }
    printf("有效输入%d次，平均成绩%f, 不及格%d人。", n, sum / n, no);
    return 0;
}