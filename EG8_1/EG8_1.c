#include <stdio.h>

struct book
{
	float price;//�۸�
	char name[20];//����
	// ���������ַ�������Ӧ�ø��ӳ�
}; // �ṹ�������Ӧ����  ;  ��β
void main(void)
{
	struct book myBook = { 5.6,"the world is flat" };
	// �ṹ��ֻ���ڳ�ʼ��ʱ������ֵ
	printf("book name=%s,book price=%f", myBook.name, myBook.price);
}