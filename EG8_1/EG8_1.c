#include <stdio.h>

struct book
{
	float price;//价格
	char name[20];//名字
	// 名字属性字符串数组应该更加长
}; // 结构题的声明应该以  ;  结尾
void main(void)
{
	struct book myBook = { 5.6,"the world is flat" };
	// 结构体只能在初始化时批量赋值
	printf("book name=%s,book price=%f", myBook.name, myBook.price);
}