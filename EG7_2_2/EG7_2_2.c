#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// ����Ӧ�����������ָ����ʽ
void link(char *s, char *t, char *r);
int main(void)
{
	char s[128], t[128], r[256];
	printf("�������һ���ַ�����\n");
	gets(s);
	printf("������ڶ����ַ�����\n");
	gets(t);
	link(s, t, r);
	printf("���Ӻ���ַ�����\n%s", r);
	return 0;
}
void link(char *s, char *t, char *link)//; ����ķֺ�
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