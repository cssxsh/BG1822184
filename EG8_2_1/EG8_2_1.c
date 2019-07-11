#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct stu
{
	char stuId[11];		// 学生学号
	char stuName[8];	// 学生姓名
	char *courseName;	// 课程名称
	float Regular;		// 平时成绩
	float Exam;			// 考试成绩
	float Total;		// 总评成绩
};
struct stu * getStuScore(int n);
void CalcScore(int n, struct stu stus[]);
void GetMaxAndMin(int n, struct stu stus[]);
void freeStruct(struct stu * stus);

int main(void)
{
	int n;
	struct stu * stus = NULL;
	printf("请输入学生个数:\n");
	scanf("%d", &n);

	stus = getStuScore(n);
	CalcScore(n, stus);
	GetMaxAndMin(n, stus);
	freeStruct(stus);
	return 0;
}
struct stu * getStuScore(int n)
{
	char *courseName = NULL;
	struct stu * stus = NULL;
	int c = 'c';
	stus = malloc((sizeof(struct stu) * n));
	courseName = malloc((sizeof(char) * 32));

	printf("请输入课程名\n");
	while(c != EOF && c != '\n') { c = getchar(); }
	gets(courseName);

	for (int i = 0; i < n; i++)
	{
		printf("请输入第%d个学生的信息：\n", i + 1);
		scanf("%s %s", stus[i].stuId, stus[i].stuName);
		stus[i].courseName = courseName;
		scanf("%f", &stus[i].Regular);
		scanf("%f", &stus[i].Exam);
	}
	return stus;
}
void CalcScore(int n, struct stu stus[])
{
	for (int i = 0; i < n; i++)
	{
		stus[i].Total = stus[i].Regular  * 0.20 + stus[i].Exam  * 0.80;
		printf("第%d个学生总评成绩为%f\n", i + 1, stus[i].Total);
	}
}
void GetMaxAndMin(int n, struct stu stus[])
{
	struct stu * Max = NULL, *Min = NULL;
	for (int i = 0; i < n; i++)
	{
		if (Max == NULL || Max->Total < stus[i].Total)
		{
			Max = &(stus[i]);
		}
		if (Min == NULL || Min->Total > stus[i].Total)
		{
			Min = &(stus[i]);
		}
	}
	printf("最低分学生成绩信息为:\n");
	printf("学号:%s 姓名:%s 课程:%s 平时分:%f 考试分:%f 总评分:%f\n",
			Min->stuId, Min->stuName, Min->courseName, Min->Regular,
			Min->Exam, Min->Total);

	printf("最高分学生成绩信息为:\n");
	printf("学号:%s 姓名:%s 课程:%s 平时分:%f 考试分:%f 总评分:%f\n",
		Max->stuId, Max->stuName, Max->courseName, Max->Regular,
		Max->Exam, Max->Total);
}
void freeStruct(struct stu * stus)
{
	free(stus->courseName);
	free(stus);
}