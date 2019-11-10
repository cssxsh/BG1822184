#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INFO ".\\studentinfo.bin"
#define DATA ".\\scoredata.bin"
struct Student
{
	char Id[11];
	char Class[9];
	char Name[8];
};
typedef struct Student * Stus;
struct ScoreRecord
{
	char Course[32];
	char Id[11];
	char Name[8];
	float Regular;
	float Exam;
	float Total;
	struct ScoreRecord * next;
};
typedef struct ScoreRecord * Records;

// 打印菜单
// 参数type用来指定菜单的类型
void DisPlayMenu(int type)
{
	switch (type)
	{
	case 0:
		printf("1: 成绩统计\n");
		printf("2: 成绩查询\n");
		printf("3: 成绩管理\n");
		printf("4: 信息管理\n");
		printf("E: 退出程序\n");
		break;
	case 1:
		printf("1: 排序查询\n");
		printf("2: 比例查询\n");
		printf("Q: 退出模块\n");
		break;
	case 11:
		printf("1: 单科总评最高分\n");
		printf("2: 单科总评最低分\n");
		printf("3: 考核分排序\n");
		printf("4: 总评分排序\n");
		printf("Q: 退出模块\n");
		break;
	case 2:
		printf("1: 按课程查询\n");
		printf("2: 按学生查询\n");
		printf("Q: 退出模块\n");
		break;
	case 22:
		printf("1: 按姓名查询\n");
		printf("2: 按班级查询\n");
		printf("3: 按学号查询\n");
		printf("Q: 退出模块\n");
		break;
	case 3:
		printf("1: 增删记录\n");
		printf("2: 成绩导出\n");
		printf("3: 成绩导入\n");
		printf("Q: 退出模块\n");
		break;
	case 31:
		printf("1: 增加记录\n");
		printf("2: 修改记录\n");
		printf("3: 删除记录\n");
		printf("Q: 退出模块\n");
		break;
	case 4:
		printf("1: 导出文件\n");
		printf("2: 导入文件\n");
		printf("Q: 退出模块\n");
		break;
	default:
		break;
	}
	printf("请输入对应的功能序号：\n");
}

// 打印成绩记录
void printRecord(Records rec)
{
	printf("课程：%s 学号：%s 姓名：%s 平时成绩：%f 考试成绩：%f 总评成绩：%f\n",
		rec->Course, rec->Id, rec->Name, rec->Regular, rec->Exam, rec->Total);
}

// 从文件加载学生信息
int LoadStudentInfo(const char * path, Stus ** AllStu, int * num)
{
	FILE * InfoFile = NULL;
	int err;
	int number;
	Stus stu;
	
	// 打开文件
	err = fopen_s(&InfoFile, path, "r,ccs=UTF-8");
	if (err != 0) {
		fprintf(stderr, "学生信息文件打开失败！\n");
		return 1;
	}

	// 读取学生数量
	fscanf(InfoFile, "%d", &number);

	// 读取学生数据
	*AllStu = (Stus *)malloc(sizeof(Stus) * number);
	if (*AllStu == NULL)
	{
		fprintf(stderr, "内存分配失败！\n");
		return 2;
	}
	for (int i = 0; i < number; i++)
	{
		stu = (Stus)malloc(sizeof(struct Student));
		if (stu == NULL)
		{
			fprintf(stderr, "内存分配失败！\n");
			return 2;
		}

		fscanf(InfoFile, "%s %s %s", stu->Id, stu->Class, stu->Name);
		if (err != 0) {
			fprintf(stderr, "学生信息文件读取失败！\n");
			return 1;
		}
		(*AllStu)[i] = stu;
	}
	*num = number;
	return 0;
}

// 保存学生数据到文件
int SaveStudentInfo(const char * path, Stus * AllStu, int num)
{
	FILE * InfoFile = NULL;
	int err;
	int number;
	Stus stu;

	number = num;

	// 打开文件
	err = fopen_s(&InfoFile, path, "w,ccs=UTF-8");
	if (err != 0) {
		fprintf(stderr, "学生信息文件打开失败！\n");
		return 1;
	}

	// 保存学生数量
	fprintf(InfoFile, "%d\n", number);
	
	for (int i = 0; i < number; i++)
	{
		stu = AllStu[i];
		fprintf(InfoFile, "%s %s %s \n", stu->Id, stu->Class, stu->Name);
	}
	fclose(InfoFile);
	return 0;
}

// 从文件加载成绩数据
int LoadScoreData(const char * path, Records * data)
{
	FILE * InfoFile = NULL;
	int err;
	int number;
	Records head, p;

	// 打开文件
	err = fopen_s(&InfoFile, path, "r,ccs=UTF-8");
	if (err != 0) {
		fprintf(stderr, "成绩数据文件打开失败！\n");
		return 1;
	}

	// 读取数量
	fscanf(InfoFile, "%d", &number);

	// 读取数据
	head = (Records)malloc(sizeof(struct ScoreRecord));
	head->next = NULL;
	head->Total = (float)number;
	if (head == NULL)
	{
		fprintf(stderr, "内存分配失败！\n");
		fclose(InfoFile);
		return 2;
	}
	for (int i = 0; i < number; i++)
	{
		p = (Records)malloc(sizeof(struct ScoreRecord));
		if (p == NULL)
		{
			fprintf(stderr, "内存分配失败！\n");
			fclose(InfoFile);
			return 2;
		}
		fscanf(InfoFile, "%s %s %s %f %f %f", 
			p->Course, p->Id, p->Name, &(p->Regular), &(p->Exam), &(p->Total));
		p->next = head->next;
		head->next = p;
	}
	*data = head;
	fclose(InfoFile);
	return 0;
}

// 保存成绩数据到文件
int SaveScoreData(const char * path, Records * data)
{
	FILE * InfoFile = NULL;
	int err;
	int number;
	Records p;

	number = (int)(*data)->Total;

	// 打开文件
	err = fopen_s(&InfoFile, path, "w,ccs=UTF-8");
	if (err != 0) {
		fprintf(stderr, "成绩数据文件打开失败！\n");
		return 1;
	}

	// 保存数量
	fprintf(InfoFile, "%d\n", (int)((*data)->Total));
	p = *data;
	for (int i = 0; i < number; i++)
	{
		p = p->next;
		fprintf(InfoFile, "%s %s %s %f %f %f\n",
			p->Course, p->Id, p->Name, p->Regular, p->Exam, p->Total);
	}
	fclose(InfoFile);
	return 0;
}

// 根据排名查询
void GetByRank(Stus * AllStu, Records data, int stunum)
{
	char c = 'c', model;
	char temp[32];
	int flag = 1, dic = 0;
	Stus stu;
	Records p, a = NULL, b = NULL;
	Records Max = NULL;
	Records Min = NULL;

	while (flag)
	{
		DisPlayMenu(11);
		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');

		switch (model)
		{
		case '1': // 查找最高
			printf("请输入课程名：\n");
			scanf("%s", temp);
			p = data->next;
			printf("查找结果：\n");
			while (p != NULL)
			{
				if (!strcmp(p->Course, temp))
				{
					Max = (Max == NULL) ? p : Max;
					Max = (Max->Total < p->Total) ? p : Max;
				}
				p = p->next;
			}

			p = data->next;
			while (p != NULL)
			{
				if (!strcmp(p->Course, temp) && p->Total == Max->Total)
				{
					printRecord(p);
				}
				p = p->next;
			}
			if (Max == NULL) printf("没有找到合适的记录!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '2': // 查找最低
			printf("请输入课程名：\n");
			scanf("%s", temp);
			p = data->next;
			printf("查找结果：\n");
			while (p != NULL)
			{
				if (!strcmp(p->Course, temp))
				{
					Min = (Min == NULL) ? p : Min;
					Min = (Min->Total > p->Total) ? p : Min;
				}
				p = p->next;
			}

			p = data->next;
			while (p != NULL)
			{
				if (!strcmp(p->Course, temp) && p->Total == Min->Total)
				{
					printRecord(p);
				}
				p = p->next;
			}
			if (Min == NULL) printf("没有找到合适的记录!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '3': // 考试分排序
			printf("请输入课程名：\n");
			scanf("%s", temp);
			printf("请输入排序方向(0为升序，1为降序)：\n");
			scanf("%d", &dic);
			p = data->next;
			printf("排序结果：\n");
			for (int i = stunum - 1; i > 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					p = data->next;
					while (p != NULL)
					{
						if (!strcmp(p->Id, AllStu[j + 1]->Id) && !strcmp(p->Course, temp))
						{
							b = p;
							break;
						}
						p = p->next;
					}
					p = data->next;
					while (p != NULL)
					{
						if (!strcmp(p->Id, AllStu[j]->Id) && !strcmp(p->Course, temp))
						{
							a = p;
							break;
						}
						p = p->next;
					}
					if (a == NULL || b == NULL) continue;
					if ((a->Exam < b->Exam) == dic)
					{
						stu = AllStu[j];
						AllStu[j] = AllStu[j + 1];
						AllStu[j + 1] = stu;
					}
				}
			}
			for (int j = 0; j < stunum; j++)
			{
				stu = AllStu[j];

				p = data->next;
				while (p != NULL)
				{
					if (!strcmp(p->Id, stu->Id) && !strcmp(p->Course, temp))
					{
						printRecord(p);
						break;
					}
					p = p->next;
				}
			}
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '4': // 总评分排序

			printf("请输入课程名：\n");
			scanf("%s", temp);
			printf("请输入排序方向(0为升序，1为降序)：\n");
			scanf("%d", &dic);
			p = data->next;
			printf("排序结果：\n");
			for (int i = stunum - 1; i > 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					p = data->next;
					while (p != NULL)
					{
						if (!strcmp(p->Id, AllStu[j + 1]->Id) && !strcmp(p->Course, temp))
						{
							b = p;
							break;
						}
						p = p->next;
					}
					p = data->next;
					while (p != NULL)
					{
						if (!strcmp(p->Id, AllStu[j]->Id) && !strcmp(p->Course, temp))
						{
							a = p;
							break;
						}
						p = p->next;
					}
					if (a == NULL || b == NULL) continue;
					if ((a->Total < b->Total) == dic)
					{
						stu = AllStu[j];
						AllStu[j] = AllStu[j + 1];
						AllStu[j + 1] = stu;
					}
				}
			}
			for (int j = 0; j < stunum; j++)
			{
				stu = AllStu[j];

				p = data->next;
				while (p != NULL)
				{
					if (!strcmp(p->Id, stu->Id) && !strcmp(p->Course, temp))
					{
						printRecord(p);
						break;
					}
					p = p->next;
				}
			}
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case 'Q':
		default:
			flag = 0;
			break;
		}
	}
	while ((c = getchar()) != EOF && c != '\n');
}

// 根据学生的信息查询
void GetByStudentInfo(Stus * AllStu, Records data, int stunum)
{
	char c = 'c', model;
	char temp[64], class[32];
	int flag = 1, t = 0;
	Records p;
	Stus stu;

	while (flag)
	{
		DisPlayMenu(22);
		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');

		switch (model)
		{
		case '1': // 按姓名查询
			t = 0;
			printf("请输入姓名：\n");
			scanf("%s", temp);
			p = data->next;
			printf("查找结果：\n");
			while (p != NULL)
			{
				if (!strcmp(p->Name, temp))
				{
					t = 1;
					printRecord(p);
				}
				p = p->next;
			}
			if (!t) printf("没有找到合适的记录!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '2': // 按班级查询
			t = 0;
			printf("请输入班级：\n");
			scanf("%s", class);
			p = data->next;
			printf("查找结果：\n");
			for (int i = 0; i < stunum; i++)
			{
				stu = AllStu[i];
				if (!strcmp(stu->Class, class))
				{
					while (p != NULL)
					{
						if (!strcmp(p->Id, AllStu[i]->Id))
						{
							t = 1;
							printRecord(p);
						}
						p = p->next;
					}
				}
			}
			if (!t) printf("没有找到合适的记录!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '3': // 按学号查询
			t = 0;
			printf("请输入学号：\n");
			scanf("%s", temp);
			p = data->next;
			printf("查找结果：\n");
			while (p != NULL)
			{
				if (!strcmp(p->Id, temp))
				{
					t = 1;
					printRecord(p);
				}
				p = p->next;
			}
			if (!t) printf("没有找到合适的记录!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case 'Q':
		default:
			flag = 0;
			break;
		}
	}
	while ((c = getchar()) != EOF && c != '\n');
}

// 成绩记录增删改
void ChangeRecord(Stus * AllStu, Records data, int stunum)
{

	char c = 'c', model;
	char temp[64], Id[16];
	int flag = 1, t = 0;
	Records p, s;

	while (flag)
	{
		DisPlayMenu(31);
		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');

		switch (model)
		{
		case '1': // 增加记录
			s = (Records)malloc(sizeof(struct ScoreRecord));
			s->next = NULL;

			printf("请输入课程 学号 姓名 平时分 考试分 总评分（按上述顺序输入）：\n");
			scanf("%s %s %s %f %f %f",
				s->Course, s->Id, s->Name, &(s->Regular), &(s->Exam), &(s->Total));

			t = 0;
			p = data->next;
			while (p != NULL)
			{
				if (!strcmp(p->Id, s->Id) && !strcmp(p->Course, s->Course))
				{
					t = 1;
					break;
				}
				p = p->next;
			}
			if (!t)
			{

				s->next = data->next;
				data->next = s;
				data->Total = data->Total + 1;
				printf("添加完成。\n");
			}
			else
			{
				printf("记录已存在！\n");
			}
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '2': // 修改记录
			t = 0;
			printf("请输入课程 学号（按上述顺序输入）：\n");
			scanf("%s %s", temp, Id);
			p = data->next;
			printf("查找结果：\n");
			while (p != NULL)
			{
				if (!strcmp(p->Id, Id) && !strcmp(p->Course, temp))
				{
					t = 1;
					printRecord(p);
					break;
				}
				p = p->next;
			}
			if (!t)
			{
				printf("没有找到合适的记录!\n");
			}
			else
			{
				printf("平时分， 考试分， 总评分修改为（按上述顺序输入）：\n");
				scanf("%f %f %f", &(p->Regular), &(p->Exam), &(p->Total));
				printf("修改完成。\n");
			}
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '3': // 删除记录
			t = 0;
			printf("请输入课程 学号（按上述顺序输入）：\n");
			scanf("%s %s", temp, Id);
			p = data;
			printf("查找结果：\n");
			while (p->next != NULL)
			{
				if (!strcmp(p->next->Id, Id) && !strcmp(p->next->Course, temp))
				{
					t = 1;
					printRecord(p->next);
					break;
				}
				p = p->next;
			}
			if (!t)
			{
				printf("没有找到合适的记录!\n");
			}
			else
			{
				s = p->next;
				p->next = p->next->next;
				free(s);
				data->Total = data->Total - 1;
				printf("删除完成。\n");
			}
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case 'Q':
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// 成绩统计
void Memu1(Stus * AllStu, Records data, int stunum)
{
	int flag = 1, count = 0, good = 0, bad = 0;
	char c = 'c', model;
	char temp[32];
	Records p;

	while (flag)
	{
		DisPlayMenu(1);
		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');
		switch (model)
		{
		case '1': // 人员查询
			GetByRank(AllStu, data, stunum);
			break;
		case '2': // 比例查询
			printf("请输入课程名：\n");
			scanf("%s", temp);
			p = data->next;
			printf("查找结果：\n");
			while (p != NULL)
			{
				if (!strcmp(p->Course, temp))
				{
					count++;
					if (p->Total >= 0.90) good++;
					if (p->Total < 0.60) bad++;
				}
				p = p->next;
			}
			if (count == 0)
			{
				printf("课程%s不存在!\n", temp);
			}
			else
			{
				printf("课程%s优秀率%f 不及格率%f\n", temp, good / (float)count, bad / (float)count);
			}
			break;
		case 'Q': // 退出模块
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// 成绩查询
void Memu2(Stus * AllStu, Records data, int stunum)
{
	int flag = 1, t = 0;
	char c = 'c', model;
	char temp[64];
	Records p;

	while (flag)
	{
		DisPlayMenu(2);
		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');
		switch (model)
		{
		case '1': // 按课程查询
			t = 0;
			printf("请输入课程名：\n");
			scanf("%s", temp);
			p = data->next;
			printf("查找结果：\n");
			while (p != NULL)
			{
				if (!strcmp(p->Course, temp))
				{
					t = 1;
					printRecord(p);
				}
				p = p->next;
			}
			if (t == 0) printf("没有找到合适的记录!\n");
			break;
		case '2': // 按课程查询
			GetByStudentInfo(AllStu, data, stunum);
			break;
		case 'Q': // 退出模块
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// 成绩管理
void Memu3(Stus * AllStu, Records data, int stunum)
{
	int flag = 1;
	char c = 'c', model;
	char path[64];

	while (flag)
	{
		DisPlayMenu(3);
		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');
		switch (model)
		{
		case '1': // 增删记录
			ChangeRecord(AllStu, data, stunum);
			break;
		case '2': // 成绩导出
			printf("请输入导出路径：\n");
			scanf("%s", path);
			if (!SaveScoreData(path, &data))
			{
				printf("导出完成！\n");
			}
			break;
		case '3': // 成绩导出
			printf("请输入导出路径：\n");
			scanf("%s", path);
			if (!LoadScoreData(path, &data))
			{
				printf("导入完成！\n");
			}
			break;
		case 'Q': // 退出模块
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// 信息管理
void Memu4(Stus * AllStu, Records data, int stunum)
{
	int flag = 1;
	char c = 'c', model;
	char path[64];

	while (flag)
	{
		DisPlayMenu(4);
		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');
		switch (model)
		{
		case '1': // 导入文件
			printf("请输入导出路径：\n");
			scanf("%s", path);
			if (!SaveStudentInfo(path, AllStu, stunum))
			{
				printf("导出完成！\n");
			}
			break;
		case '2': // 导出文件
			printf("请输入导入路径：\n");
			scanf("%s", path);
			if (!LoadStudentInfo(path, &AllStu, &stunum))
			{
				printf("导入完成！\n");
			}
			break;
			break;
		case 'Q': // 退出模块
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// 主菜单
void MainMemu(Stus * AllStu, Records data, int stunum)
{
	int flag = 1;
	char c = 'c', model;

	while (flag)
	{

		DisPlayMenu(0);

		model = getchar();
		while ((c = getchar()) != EOF && c != '\n');
		switch (model)
		{
		case '1': // 成绩统计
			Memu1(AllStu, data, stunum);
			break;
		case '2': // 成绩查询
			Memu2(AllStu, data, stunum);
			break;
		case '3': // 成绩管理
			Memu3(AllStu, data, stunum);
			break;
		case '4': // 信息管理
			Memu4(AllStu, data, stunum);
			break;
		case 'E': // 退出程序
		default:
			flag = 0;
			break;
		}
	}
}

void FreeStruct(Stus * AllStu, Records data, int stunum)
{
	Records p;

	for (int i = 0; i < stunum; i++)
	{
		free(AllStu[i]);
	}
	free(AllStu);

	while (data->next != NULL)
	{

		p = data->next;
		data->next = data->next->next;
		free(p);
	}
	free(data);
}