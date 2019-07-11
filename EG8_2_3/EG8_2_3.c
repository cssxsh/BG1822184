#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


struct stu
{
	char stuId[11];		// ѧ��ѧ��
	char stuName[8];	// ѧ������
	char *courseName;	// �γ�����
	float Regular;		// ƽʱ�ɼ�
	float Exam;			// ���Գɼ�
	float Total;		// �����ɼ�
};
struct stu * getStuScore(int n, FILE * in);
void CalcScore(int n, struct stu stus[], FILE * out);
void GetMaxAndMin(int n, struct stu stus[], FILE * out);
void freeStruct(struct stu * stus);

int main(void)
{
	int n;
	struct stu * stus = NULL;
	FILE *data_txt;
	FILE *T_data_txt;


	data_txt = fopen("D:\\Users\\CSSXSH\\Documents\\$ c_work\\BG1822184\\Debug\\data.txt", "r");
	T_data_txt  = fopen("D:\\Users\\CSSXSH\\Documents\\$ c_work\\BG1822184\\Debug\\T_data.txt", "w");

	fscanf(data_txt, "%d", &n);
	stus = getStuScore(n, data_txt);
	CalcScore(n, stus, T_data_txt);
	GetMaxAndMin(n, stus, T_data_txt);
	freeStruct(stus);
	fclose(data_txt);
	fclose(T_data_txt);
	return 0;
}
struct stu * getStuScore(int n, FILE * in)
{
	char *courseName = NULL;
	struct stu * stus = NULL;
	int c = 'c';
	stus = malloc((sizeof(struct stu) * n));
	courseName = malloc((sizeof(char) * 32));

	while (c != EOF && c != '\n') { c = fgetc(in); }
	fgets(courseName, 32, in);

	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%s %s", stus[i].stuId, stus[i].stuName);
		stus[i].courseName = courseName;
		fscanf(in, "%f", &stus[i].Regular);
		fscanf(in, "%f", &stus[i].Exam);
	}
	return stus;
}
void CalcScore(int n, struct stu stus[], FILE * out)
{
	for (int i = 0; i < n; i++)
	{
		stus[i].Total = stus[i].Regular  * 0.20 + stus[i].Exam  * 0.80;
		fprintf(out, "��%d��ѧ�������ɼ�Ϊ%f\n", i + 1, stus[i].Total);
	}
}
void GetMaxAndMin(int n, struct stu stus[], FILE * out)
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
	fprintf(out, "��ͷ�ѧ���ɼ���ϢΪ:\n");
	fprintf(out, "ѧ��:%s ����:%s �γ�:%s ƽʱ��:%f ���Է�:%f ������:%f\n",
		Min->stuId, Min->stuName, Min->courseName, Min->Regular,
		Min->Exam, Min->Total);

	fprintf(out, "��߷�ѧ���ɼ���ϢΪ:\n");
	fprintf(out, "ѧ��:%s ����:%s �γ�:%s ƽʱ��:%f ���Է�:%f ������:%f\n",
		Max->stuId, Max->stuName, Max->courseName, Max->Regular,
		Max->Exam, Max->Total);
}
void freeStruct(struct stu * stus)
{
	free(stus->courseName);
	free(stus);
}