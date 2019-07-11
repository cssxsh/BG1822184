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

	// ������ͷ�ڵ����������
	head = init();
	printlist(head);
	
	// ��ѯ�ڵ�
	printf("������Ҫ��ѯ�ڵ����ţ�");
	scanf("%d", &n);
	p = getAt(head, n);
	printf("���Ϊ%d�Ľ���ֵΪ��%d\n", n, p->num);
	
	// ���ҽڵ�
	printf("������Ҫ���ҽڵ��ֵ��");
	scanf("%d", &x);
	i = find(head, x);
	printf("ֵΪ%d�Ľ������Ϊ��%d\n", x, i);

	// ������
	printf("��������� n��ֵx��");
	scanf("%d %d", &n, &x);
	insert(head, n, x);
	printlist(head);

	// ɾ�����
	printf("������Ҫɾ���ڵ����ţ�");
	scanf("%d", &n);
	delete(head, n);
	printlist(head);
	
	return  0;
}

struct stud_node * init(void)
{
	struct stud_node *head;
	struct stud_node *next;

	// ����ʹ�õ�����ͷ�ڵ������
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
	printf("��ӡ����%p\n", head);
	struct stud_node * p;
	int i = 1;
	p = head->next;
	while (p != NULL)
	{
		printf("%d: %d\n", i++, p->num);
		p = p->next;
	}
}