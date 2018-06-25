//
//  main.c
//  student&teacher
//
//  Created by 20161104600 on 18/6/25.
//  Copyright © 2018年 20161104600. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define MAXSIZE 30
struct Student
{
    char name[10];
    char sex;
    char proname[10];
    char protype[10];
    int num;
    char class[10];
    int Score;
};
typedef struct Student ElemTypeS;

typedef struct
{
    ElemTypeS elem[MAXSIZE];
    int lastS;
}SeqListS;

struct Teacher
{
    char name[10];
    char sex;
    int num;
    int Score;
};
typedef struct Teacher ElemTypeT;

typedef struct
{
    ElemTypeT elem[MAXSIZE];
    int lastT;
}SeqListT;

char menu()
{
    int input;
    printf("\n");
    printf("         |************评分系统*************|        \n");
    printf("         |--------------------------------|        \n");
    printf("         |            菜单选项             |        \n");
    printf("         |--------------------------------|        \n");
    printf("         |    1---输入                    |        \n");
    printf("         |    2---增加                    |        \n");
    printf("         |    3---删除                    |        \n");
    printf("         |    4---修改                    |        \n");
    printf("         |    5---查找                    |        \n");
    printf("         |    6---评分                    |        \n");
    printf("         |    7---在文件中读取              |        \n");
    printf("         |    8---保存到文件中              |        \n");
    printf("         |    9---退出                    |        \n");
    
    do
    {
        printf("\n选择你要进行的操作(1-9):");
        scanf("%d",&input);
    }
    while(input<1 || input>9);
    return input;
}


void sortMax(SeqListT *L)
{
    int i,j;
    ElemTypeT X;
    for(j=0;j<L->lastT-1;j++)
    {
        for(i=0;i<=L->lastT-1-j;i++)
        {
            if(L->elem[i].Score<L->elem[i+1].Score)
            {
                X=L->elem[i];
                L->elem[i]=L->elem[i+1];
                L->elem[i+1]=X;
            }
        }
    }
}

void readin(SeqListT *L)// 输入老师相关信息
{
    int r;
    int i;
    printf("输入想要录入教师的数量:");
    scanf("%d",&r);
    //char name1[10];
    for(i=0; i<=r-1; i++)
    {
        //ElemType X;
        //scanf("%d",&X.num);
        //scanf("%d",&X.score);
        //L->elem[i]=X;
        /*
         char name[10];
         int num;
         int MathScore;
         int ChinaseScore;
         int EnglishScore;
         */
        L->lastT++;
        printf("----------------------------\n");
        printf("请输入第%d名老师的信息：\n",i+1);
        printf("请输入老师的姓名\n");
        scanf("%s",L->elem[i].name);
        //strcpy(L->elem[i].name,name1);
        printf("请输入老师的性别：\n");
        scanf("%c",&L->elem[i].sex);
        printf("请输入老师的联系方式：\n");
        scanf("%d",&L->elem[i].num);
    }
}



int main()
{
    SeqListS l1;
    SeqListT l2;
    l1.lastS=-1;
    l2.lastT=-1;
    while(1)
    {
        switch(menu())
        {
            case 1:
                readin(&l);//输入
                display(l);
                break;
            case 2:
                find(l);//增加
                break;
            case 3:
                Insert(&l);	//删除
                display(l);
                break;
            case 4:
                delet(&l);//修改
                display(l);
                break;
            case 5:
                display(l);//查找
                break;
            case 6:
                sort(&l);//评分
                display(l); 
                break;
            case 7:
                save(&l);//读取
                break;
            case 8:
                load(&l);//保存
                break;	
            case 9:
                printf("-----–谢谢使用-----\n");
                exit(1);
        }
    }
}

