#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "EDU.h"

int main(void)
{
    Stus *AllStu = NULL;
    int stunum;
    Records data = NULL;

    LoadScoreData(DATA, &data);
    LoadStudentInfo(INFO, &AllStu, &stunum);
    // 进入主菜单
    MainMemu(AllStu, data, stunum);

    // 释放资源
    FreeStruct(AllStu, data, stunum);
    return 0;
}