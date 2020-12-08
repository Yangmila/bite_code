#include <stdio.h>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define COUNT 512

using namespace std;

typedef struct NODE
{
    char name;//����
    float start;//��ʼλ��
    float end;//��С
    int flag;//�Ƿ����ı�־
}NODE;

//ȫ�ֱ�������
NODE OS[COUNT];//����
int count;//���ֳɵĿ���ͳ��
int applyfree;
float numb;
char c;

void init()//�ȶ�������г�ʼ����ʹû�з��������Ϊ P
{
    count=1;
    OS[0].name ='P';
    OS[0].start =0;
    OS[0].end =COUNT;
    OS[0].flag =1;
}

void insert(int m,float st,float en)//������Ĳ������
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

void move(int m)//�ƶ����������������ɾ������
{
    int i;
    
    for(i=m;i<count-1;i++)
    {
        OS[i]=OS[i+1];
    }
    count--;
}


void rremove(int m,float st,float en)//������ڿ鶼û�з��䣬��Ҫ�ϲ���һ��
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

void show()//��ӡ���
{
    int i;
    printf("����    ��ʶ    ��ַ    ����    ״̬\n");
    
    for(i=0;i<count;i++)
    {
        if(OS[i].flag )
            printf("P    ");
        else
            printf("%c    ",OS[i].name );

        printf("%d    %1.0f    %1.0f    ",i,OS[i].start ,OS[i].end );
        
        if(OS[i].flag )
            printf("δ����\n");
        else
            printf("�ѷ���\n");
    }
}

void putin()//�Ӽ�����������
{
    printf("��������������ͷŵĽ������Ƽ���Դ������\n");
    
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
    
    if(applyfree)//���������Դ
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
            printf("����ɹ���\n");
            return 1;
        }
        else
        {
            printf("����ʧ�ܣ�û���㹻��Ŀ��пռ䡣\n");
            return 0;
        }
    }
    else//����ͷ���Դ
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
                        printf("�ͷ�ʧ�ܣ���Ϊ��ʹ�õ�����С��Ҫ���ͷŵ�������\n");
                        return 0;
                    }
                }
                freeflag=1;
            }
            i++;
        }
        
        if(freeflag)
        {
            printf("�ͷųɹ���\n");
            return 1;
        }
        else
        {
            printf("�ͷ�ʧ�ܣ�δ�ҵ�ƥ��Ľ������ơ�\n");
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
