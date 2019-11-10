#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	char sex, sports, diet;
	double faHeight, moHeight;
	double prediction;
	double coef = 1.0;
	printf("请输入你的性别（男：M/女：F）：");
	scanf(" %c", &sex);
	printf("是否喜欢体育锻炼（是：Y/否：N）：");
	scanf(" %c", &sports);
	printf("是否有良好的饮食习惯等条件（是：Y/否：N）：");
	scanf(" %c", &diet);
	printf("请输入你父亲的身高（单位：cm）：");
	scanf("%lf", &faHeight);
	printf("请输入你母亲的身高（单位：cm）：");
	scanf("%lf", &moHeight);
	prediction = (sex == 'M') ? (faHeight + moHeight) * 0.54 : (faHeight * 0.923 + moHeight) / 2.0;
	if (sports == 'Y') coef += 0.02;
	if (diet == 'Y') coef += 0.015;
	prediction *= coef;
	printf("对你身高的预测为：%lf", prediction);
	return 0;
}