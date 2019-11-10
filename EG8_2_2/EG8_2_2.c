#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct book
{
    char Name[32]; // 书名
    float Price;   // 单价
};

void Sort(int n, struct book *books);
void exchange(struct book *a, struct book *b);

int main(void)
{
    int n;
    struct book *books = NULL;

    printf("请输入书本数:\n");
    scanf("%d", &n);

    books = malloc((sizeof(struct book) * n));

    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d本书的信息：\n", i + 1);
        scanf("%s", &books[i].Name);
        scanf("%f", &books[i].Price);
    }
    Sort(n, books);

    printf("\n排序后书本信息：\n");
    for (int i = 0; i < n; i++)
    {
        printf("第%d本书的信息：书名：%s 单价：%f\n",
               i + 1, books[i].Name, books[i].Price);
    }

    free(books);
    return 0;
}
void Sort(int n, struct book *books)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (books[j - 1].Price > books[j].Price)
            {
                exchange(&(books[j - 1]), &(books[j]));
            }
        }
    }
}
void exchange(struct book *a, struct book *b)
{
    char c;
    float temp;

    temp = a->Price;
    a->Price = b->Price;
    b->Price = temp;

    for (int i = 0; i < 32; i++)
    {
        c = a->Name[i];
        a->Name[i] = b->Name[i];
        b->Name[i] = c;
    }
}
