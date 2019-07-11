#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 
#define len 6
const int arr[6] = { 21, 3, 15, 27, 11, 18 };
struct stud_node
{
	int num;
	struct stud_node *next;
};
struct stud_node * init(void);
void printlist(struct stud_node * head);
struct stud_node * getAt(struct stud_node * head, int n);
int find(struct stud_node * head, int x);
void insert(struct stud_node * head, int n, int x);
void delete(struct stud_node * head, int n);

int main()
{
	struct stud_node *head = NULL, *p = NULL;
	int n, i;
	int x;

	// 创建带头节点的有序链表
	head = init();
	printlist(head);
	
	// 查询节点
	printf("请输入要查询节点的序号：");
	scanf("%d", &n);
	p = getAt(head, n);
	printf("序号为%d的结点的值为：%d\n", n, p->num);
	
	// 查找节点
	printf("请输入要查找节点的值：");
	scanf("%d", &x);
	i = find(head, x);
	printf("值为%d的结点的序号为：%d\n", x, i);

	// 插入结点
	printf("请输入序号 n和值x：");
	scanf("%d %d", &n, &x);
	insert(head, n, x);
	printlist(head);

	// 删除结点
	printf("请输入要删除节点的序号：");
	scanf("%d", &n);
	delete(head, n);
	printlist(head);
	
	return  0;
}

struct stud_node * init(void)
{
	struct stud_node *head;
	struct stud_node *next;

	// 这里使用的是有头节点的链表
	head = malloc(sizeof(struct stud_node));
	head->next = NULL;

	for (int i = 5; i >= 0; i--)
	{
		next = malloc(sizeof(struct stud_node));
		next->next = head->next;
		next->num = arr[i];
		head->next = next;
	}
	return head;
}
struct stud_node * getAt(struct stud_node * head, int n)
{
	struct stud_node * p = head;
	for (int i = 0; i < n; i++)
	{
		p = p->next;
	}
	return p;
}
int find(struct stud_node * head, int x)
{
	struct stud_node * p = head;
	int i = 0;
	while(p->next != NULL)
	{
		if (p->next->num != x)
		{
			p = p->next;
			i++;
		}
		else
		{
			break;
		}
	}
	return i + 1;
}
void insert(struct stud_node * head, int n, int x)
{
	struct stud_node * p, *next;
	p = getAt(head, n);
	next = malloc(sizeof(struct stud_node));
	next->num = x;
	next->next = p->next;
	p->next = next;
}
void delete(struct stud_node * head, int n)
{
	struct stud_node * p, *next;
	p = getAt(head, n - 1);
	next = p->next;
	p->next = p->next->next;
	free(next);
}
void printlist(struct stud_node * head)
{
	printf("打印链表%p\n", head);
	struct stud_node * p;
	int i = 1;
	p = head->next;
	while (p != NULL)
	{
		printf("%d: %d\n", i++, p->num);
		p = p->next;
	}
}