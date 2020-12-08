#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define COUNT 512

using namespace std;

typedef struct NODE
{
    char name;//名称
    float start;//起始位置
    float end;//大小
    int flag;//是否分配的标志
}NODE;

//全局变量定义
NODE OS[COUNT];//数组
int count;//被分成的块数统计
int applyfree;
float numb;
char c;

void init()//先对数组进行初始化，使没有分配的名称为 P
{
    count=1;
    OS[0].name ='P';
    OS[0].start =0;
    OS[0].end =COUNT;
    OS[0].flag =1;
}

void insert(int m,float st,float en)//对数组的插入操作
{
    int i;
    count++;
    
    for(i=count;i>m+1;i--)
    {
        OS[i]=OS[i-1];
    }
    
    OS[m].start =st;
    OS[m].end  =en;
}

void move(int m)//移动操作，即对数组的删除操作
{
    int i;
    
    for(i=m;i<count-1;i++)
    {
        OS[i]=OS[i+1];
    }
    count--;
}


void rremove(int m,float st,float en)//如果相邻块都没有分配，则要合并到一起
{
    if(!OS[m-1].flag &&!OS[m+1].flag )
    {
        OS[m].name ='P';
        OS[m].flag =1;
    }
    
    if(OS[m-1].flag )
    {
        OS[m-1].end =OS[m-1].end +en;
        move(m);
    }
    
    if(OS[m+1].flag )
    {
        OS[m].end =OS[m].end +OS[m+1].end ;
        OS[m].name ='P';
        OS[m].flag =1;
        move(m+1);
    }
}

void show()//打印输出
{
    int i;
    printf("名称    标识    起址    长度    状态\n");
    
    for(i=0;i<count;i++)
    {
        if(OS[i].flag )
            printf("P    ");
        else
            printf("%c    ",OS[i].name );

        printf("%d    %1.0f    %1.0f    ",i,OS[i].start ,OS[i].end );
        
        if(OS[i].flag )
            printf("未分配\n");
        else
            printf("已分配\n");
    }
}

void putin()//从键盘输入数据
{
    printf("请输入申请或者释放的进程名称及资源数量：\n");
    
    rewind(stdin);
    
    scanf("%c",&c);
    scanf("%d",&applyfree);
    scanf("%f",&numb);
}

int apply()
{
    int i=0;
    int applyflag=0;
    int freeflag=0;
    
    if(applyfree)//提出申请资源
    {
        while(!applyflag&&i<count)
        {
            if(OS[i].end >=numb&&OS[i].flag )
            {
                if(OS[i].end ==numb)
                {
                    OS[i].name =c;
                    OS[i].flag =0;
                }
                else
                {

                    insert(i+1,OS[i].start +numb,OS[i].end -numb);
                    OS[i+1].flag =1;
                    OS[i+1].name ='P';
                    OS[i].start =OS[i].start ;
                    OS[i].name =c;
                    OS[i].end =numb;
                    OS[i].flag =0;
                }
                applyflag=1;
            }
            i++;
        }
        
        if(applyflag)
        {
            printf("申请成功！\n");
            return 1;
        }
        else
        {
            printf("申请失败！没有足够大的空闲空间。\n");
            return 0;
        }
    }
    else//提出释放资源
    {
        while(!freeflag&&i<count)
        {
            if(OS[i].name ==c)
            {
                if(OS[i].end ==numb)
                {
                rremove(i,OS[i].start ,OS[i].end );
                }
                else
                {
                    if(OS[i].end >numb)
                    {

                            insert(i+1,OS[i].start +numb,OS[i].end -numb);
                            OS[i+1].name ='P';
                            OS[i+1].flag =0;
                            OS[i].end =numb;
                            OS[i].flag =1;
                            
                            if(OS[i-1].flag )
                            {
                                rremove(i,OS[i].start ,OS[i].end );
                            }
                    }
                    else
                    {
                        printf("释放失败，因为正使用的数量小于要求释放的数量。\n");
                        return 0;
                    }
                }
                freeflag=1;
            }
            i++;
        }
        
        if(freeflag)
        {
            printf("释放成功！\n");
            return 1;
        }
        else
        {
            printf("释放失败！未找到匹配的进程名称。\n");
            return 0;
        }
    }
}

int main()
{
    init();
    show();
    
    while(1)
    {
        putin();
        apply();
        show();
    }
    return 0;
}
