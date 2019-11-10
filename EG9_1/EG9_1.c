#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node
{
    int num;
    char name[20];
    int score;
    struct stud_node *next;
};
int main()
{
    struct stud_node *head = NULL, *tail = NULL, *p = NULL;
    int num, score;
    char name[20];
    const int size = sizeof(struct stud_node);

    head = tail = NULL;
    printf("input num, name and score:\n");
    scanf("%d", &num);
    while (num != 0)
    {
        p = malloc(size);
        scanf("%s %d", name, &score);
        p->num = num;
        strcpy(p->name, name);
        p->score = score;
        p->next = NULL;
        // 当链表为空时，赋值不一样
        // 建议使用带头节点的的链表
        if (head != NULL)
        {
            tail->next = p;
        }
        else
        {
            tail = p;
            head = p;
            head->next = tail;
        }
        tail = p;
        scanf("%d", &num);
    }
    for (p = head; p->next != NULL; p = p->next)
        printf("%d  %s  %d\n", p->num, p->name, p->score);
    return 0;
}