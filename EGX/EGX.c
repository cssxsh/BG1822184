#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "EDU.H"

int main(void)
{
	Stus * AllStu = NULL;
	int stunum;
	Records data = NULL;

	LoadScoreData(DATA, &data);
	LoadStudentInfo(INFO, &AllStu, &stunum);
	// �������˵�
	MainMemu(AllStu, data, stunum);

	// �ͷ���Դ
	FreeStruct(AllStu, data, stunum);
	return 0;
}