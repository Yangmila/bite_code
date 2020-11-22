#include <stdio.h>
#include<stdlib.h>
#include<time.h>
void Guess()
{
	int radom=rand()%100+1;
	int cin=0;
	while(1)
	{
		printf("请输入你猜的数：");
		scanf("%d",&cin);
		if(cin>radom)
		{
			printf("你猜的数大了！\n");
		}
		else if(cin<radom)
		{
			printf("你猜的数小了！\n");
		}
		else
		{
			printf("恭喜你，你猜对了！\n");
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
		printf("*      猜数游戏      *\n");
		printf("**********************\n");
		printf("     1.开始游戏\n");
		printf("     2.退出游戏\n");
		printf("请选择：\n");
		scanf("%d",&option);
		if(option<1||option>2)
		{
			printf("选择功能时发生错误，请重新选择！\n\n\n");
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
