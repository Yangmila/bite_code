#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void Guess()
{
	int radom=rand()%100+1;
	int cin=0;
	while(1)
	{
		printf("��������µ�����");
		scanf("%d",&cin);
		if(cin>radom)
		{
			printf("��µ������ˣ�\n");
		}
		else if(cin<radom)
		{
			printf("��µ���С�ˣ�\n");
		}
		else
		{
			printf("��ϲ�㣬��¶��ˣ�\n");
			break;
		 } 
	}
}
int main()
{
	int option;
	int num;
	while(1)
	{
		printf("**********************\n");
		printf("*      ������Ϸ      *\n");
		printf("**********************\n");
		printf("     1.��ʼ��Ϸ\n");
		printf("     2.�˳���Ϸ\n");
		printf("��ѡ��\n");
		scanf("%d",&option);
		if(option<1||option>2)
		{
			printf("ѡ����ʱ��������������ѡ��\n\n\n");
			continue;
		}
		
		if(option==2)
		{
			break;
		} 
		
		switch(option)
		{
			case 1: Guess( );
					break;
		} 
	}
	return 0;
 } 
