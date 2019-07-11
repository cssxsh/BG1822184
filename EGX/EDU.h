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

// ��ӡ�˵�
// ����type����ָ���˵�������
void DisPlayMenu(int type)
{
	switch (type)
	{
	case 0:
		printf("1: �ɼ�ͳ��\n");
		printf("2: �ɼ���ѯ\n");
		printf("3: �ɼ�����\n");
		printf("4: ��Ϣ����\n");
		printf("E: �˳�����\n");
		break;
	case 1:
		printf("1: �����ѯ\n");
		printf("2: ������ѯ\n");
		printf("Q: �˳�ģ��\n");
		break;
	case 11:
		printf("1: ����������߷�\n");
		printf("2: ����������ͷ�\n");
		printf("3: ���˷�����\n");
		printf("4: ����������\n");
		printf("Q: �˳�ģ��\n");
		break;
	case 2:
		printf("1: ���γ̲�ѯ\n");
		printf("2: ��ѧ����ѯ\n");
		printf("Q: �˳�ģ��\n");
		break;
	case 22:
		printf("1: ��������ѯ\n");
		printf("2: ���༶��ѯ\n");
		printf("3: ��ѧ�Ų�ѯ\n");
		printf("Q: �˳�ģ��\n");
		break;
	case 3:
		printf("1: ��ɾ��¼\n");
		printf("2: �ɼ�����\n");
		printf("3: �ɼ�����\n");
		printf("Q: �˳�ģ��\n");
		break;
	case 31:
		printf("1: ���Ӽ�¼\n");
		printf("2: �޸ļ�¼\n");
		printf("3: ɾ����¼\n");
		printf("Q: �˳�ģ��\n");
		break;
	case 4:
		printf("1: �����ļ�\n");
		printf("2: �����ļ�\n");
		printf("Q: �˳�ģ��\n");
		break;
	default:
		break;
	}
	printf("�������Ӧ�Ĺ�����ţ�\n");
}

// ��ӡ�ɼ���¼
void printRecord(Records rec)
{
	printf("�γ̣�%s ѧ�ţ�%s ������%s ƽʱ�ɼ���%f ���Գɼ���%f �����ɼ���%f\n",
		rec->Course, rec->Id, rec->Name, rec->Regular, rec->Exam, rec->Total);
}

// ���ļ�����ѧ����Ϣ
int LoadStudentInfo(const char * path, Stus ** AllStu, int * num)
{
	FILE * InfoFile = NULL;
	errno_t err;
	int number;
	Stus stu;
	
	// ���ļ�
	err = fopen_s(&InfoFile, path, "r");
	if (err != 0) {
		fprintf(stderr, "ѧ����Ϣ�ļ���ʧ�ܣ�\n");
		return 1;
	}

	// ��ȡѧ������
	fscanf(InfoFile, "%d", &number);

	// ��ȡѧ������
	*AllStu = (Stus *)malloc(sizeof(Stus) * number);
	if (*AllStu == NULL)
	{
		fprintf(stderr, "�ڴ����ʧ�ܣ�\n");
		return 2;
	}
	for (int i = 0; i < number; i++)
	{
		stu = (Stus)malloc(sizeof(struct Student));
		if (stu == NULL)
		{
			fprintf(stderr, "�ڴ����ʧ�ܣ�\n");
			return 2;
		}

		fscanf(InfoFile, "%s %s %s", stu->Id, stu->Class, stu->Name);
		if (err != 0) {
			fprintf(stderr, "ѧ����Ϣ�ļ���ȡʧ�ܣ�\n");
			return 1;
		}
		(*AllStu)[i] = stu;
	}
	*num = number;
	return 0;
}

// ����ѧ�����ݵ��ļ�
int SaveStudentInfo(const char * path, Stus * AllStu, int num)
{
	FILE * InfoFile = NULL;
	errno_t err;
	int number;
	Stus stu;

	number = num;

	// ���ļ�
	err = fopen_s(&InfoFile, path, "w");
	if (err != 0) {
		fprintf(stderr, "ѧ����Ϣ�ļ���ʧ�ܣ�\n");
		return 1;
	}

	// ����ѧ������
	fprintf(InfoFile, "%d\n", number);
	
	for (int i = 0; i < number; i++)
	{
		stu = AllStu[i];
		fprintf(InfoFile, "%s %s %s \n", stu->Id, stu->Class, stu->Name);
	}
	fclose(InfoFile);
	return 0;
}

// ���ļ����سɼ�����
int LoadScoreData(const char * path, Records * data)
{
	FILE * InfoFile = NULL;
	errno_t err;
	int number;
	Records head, p;

	// ���ļ�
	err = fopen_s(&InfoFile, path, "r");
	if (err != 0) {
		fprintf(stderr, "�ɼ������ļ���ʧ�ܣ�\n");
		return 1;
	}

	// ��ȡ����
	fscanf(InfoFile, "%d", &number);

	// ��ȡ����
	head = (Records)malloc(sizeof(struct ScoreRecord));
	head->next = NULL;
	head->Total = (float)number;
	if (head == NULL)
	{
		fprintf(stderr, "�ڴ����ʧ�ܣ�\n");
		fclose(InfoFile);
		return 2;
	}
	for (int i = 0; i < number; i++)
	{
		p = (Records)malloc(sizeof(struct ScoreRecord));
		if (p == NULL)
		{
			fprintf(stderr, "�ڴ����ʧ�ܣ�\n");
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

// ����ɼ����ݵ��ļ�
int SaveScoreData(const char * path, Records * data)
{
	FILE * InfoFile = NULL;
	errno_t err;
	int number;
	Records p;

	number = (int)(*data)->Total;

	// ���ļ�
	err = fopen_s(&InfoFile, path, "w");
	if (err != 0) {
		fprintf(stderr, "�ɼ������ļ���ʧ�ܣ�\n");
		return 1;
	}

	// ��������
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

// ����������ѯ
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
		case '1': // �������
			printf("������γ�����\n");
			scanf("%s", temp);
			p = data->next;
			printf("���ҽ����\n");
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
			if (Max == NULL) printf("û���ҵ����ʵļ�¼!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '2': // �������
			printf("������γ�����\n");
			scanf("%s", temp);
			p = data->next;
			printf("���ҽ����\n");
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
			if (Min == NULL) printf("û���ҵ����ʵļ�¼!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '3': // ���Է�����
			printf("������γ�����\n");
			scanf("%s", temp);
			printf("������������(0Ϊ����1Ϊ����)��\n");
			scanf("%d", &dic);
			p = data->next;
			printf("��������\n");
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
		case '4': // ����������

			printf("������γ�����\n");
			scanf("%s", temp);
			printf("������������(0Ϊ����1Ϊ����)��\n");
			scanf("%d", &dic);
			p = data->next;
			printf("��������\n");
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

// ����ѧ������Ϣ��ѯ
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
		case '1': // ��������ѯ
			t = 0;
			printf("������������\n");
			scanf("%s", temp);
			p = data->next;
			printf("���ҽ����\n");
			while (p != NULL)
			{
				if (!strcmp(p->Name, temp))
				{
					t = 1;
					printRecord(p);
				}
				p = p->next;
			}
			if (!t) printf("û���ҵ����ʵļ�¼!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '2': // ���༶��ѯ
			t = 0;
			printf("������༶��\n");
			scanf("%s", class);
			p = data->next;
			printf("���ҽ����\n");
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
			if (!t) printf("û���ҵ����ʵļ�¼!\n");
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '3': // ��ѧ�Ų�ѯ
			t = 0;
			printf("������ѧ�ţ�\n");
			scanf("%s", temp);
			p = data->next;
			printf("���ҽ����\n");
			while (p != NULL)
			{
				if (!strcmp(p->Id, temp))
				{
					t = 1;
					printRecord(p);
				}
				p = p->next;
			}
			if (!t) printf("û���ҵ����ʵļ�¼!\n");
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

// �ɼ���¼��ɾ��
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
		case '1': // ���Ӽ�¼
			s = (Records)malloc(sizeof(struct ScoreRecord));
			s->next = NULL;

			printf("������γ� ѧ�� ���� ƽʱ�� ���Է� �����֣�������˳�����룩��\n");
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
				printf("�����ɡ�\n");
			}
			else
			{
				printf("��¼�Ѵ��ڣ�\n");
			}
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '2': // �޸ļ�¼
			t = 0;
			printf("������γ� ѧ�ţ�������˳�����룩��\n");
			scanf("%s %s", temp, Id);
			p = data->next;
			printf("���ҽ����\n");
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
				printf("û���ҵ����ʵļ�¼!\n");
			}
			else
			{
				printf("ƽʱ�֣� ���Է֣� �������޸�Ϊ��������˳�����룩��\n");
				scanf("%f %f %f", &(p->Regular), &(p->Exam), &(p->Total));
				printf("�޸���ɡ�\n");
			}
			while ((c = getchar()) != EOF && c != '\n');
			break;
		case '3': // ɾ����¼
			t = 0;
			printf("������γ� ѧ�ţ�������˳�����룩��\n");
			scanf("%s %s", temp, Id);
			p = data;
			printf("���ҽ����\n");
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
				printf("û���ҵ����ʵļ�¼!\n");
			}
			else
			{
				s = p->next;
				p->next = p->next->next;
				free(s);
				data->Total = data->Total - 1;
				printf("ɾ����ɡ�\n");
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

// �ɼ�ͳ��
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
		case '1': // ��Ա��ѯ
			GetByRank(AllStu, data, stunum);
			break;
		case '2': // ������ѯ
			printf("������γ�����\n");
			scanf("%s", temp);
			p = data->next;
			printf("���ҽ����\n");
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
				printf("�γ�%s������!\n", temp);
			}
			else
			{
				printf("�γ�%s������%f ��������%f\n", temp, good / (float)count, bad / (float)count);
			}
			break;
		case 'Q': // �˳�ģ��
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// �ɼ���ѯ
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
		case '1': // ���γ̲�ѯ
			t = 0;
			printf("������γ�����\n");
			scanf("%s", temp);
			p = data->next;
			printf("���ҽ����\n");
			while (p != NULL)
			{
				if (!strcmp(p->Course, temp))
				{
					t = 1;
					printRecord(p);
				}
				p = p->next;
			}
			if (t == 0) printf("û���ҵ����ʵļ�¼!\n");
			break;
		case '2': // ���γ̲�ѯ
			GetByStudentInfo(AllStu, data, stunum);
			break;
		case 'Q': // �˳�ģ��
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// �ɼ�����
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
		case '1': // ��ɾ��¼
			ChangeRecord(AllStu, data, stunum);
			break;
		case '2': // �ɼ�����
			printf("�����뵼��·����\n");
			scanf("%s", path);
			if (!SaveScoreData(path, &data))
			{
				printf("������ɣ�\n");
			}
			break;
		case '3': // �ɼ�����
			printf("�����뵼��·����\n");
			scanf("%s", path);
			if (!LoadScoreData(path, &data))
			{
				printf("������ɣ�\n");
			}
			break;
		case 'Q': // �˳�ģ��
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// ��Ϣ����
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
		case '1': // �����ļ�
			printf("�����뵼��·����\n");
			scanf("%s", path);
			if (!SaveStudentInfo(path, AllStu, stunum))
			{
				printf("������ɣ�\n");
			}
			break;
		case '2': // �����ļ�
			printf("�����뵼��·����\n");
			scanf("%s", path);
			if (!LoadStudentInfo(path, &AllStu, &stunum))
			{
				printf("������ɣ�\n");
			}
			break;
			break;
		case 'Q': // �˳�ģ��
		default:
			flag = 0;
			break;
		}
	}

	while ((c = getchar()) != EOF && c != '\n');
}

// ���˵�
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
		case '1': // �ɼ�ͳ��
			Memu1(AllStu, data, stunum);
			break;
		case '2': // �ɼ���ѯ
			Memu2(AllStu, data, stunum);
			break;
		case '3': // �ɼ�����
			Memu3(AllStu, data, stunum);
			break;
		case '4': // ��Ϣ����
			Memu4(AllStu, data, stunum);
			break;
		case 'E': // �˳�����
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