#include <stdio.h>                                        

main()
{
	float a,b,c;											//定义三角形的三条边
	printf("请输入您想判断的三角形的三条边:");        
	scanf("%f%f%f",&a,&b,&c);                              //输入三条边
												//第一步：
	if(a+b>c && a+c>b && b+c>a)								//判定三角形是否成立的条件
	{											//第二步：			
		if(a==b && a==c)									//先判断三角形是否为等边三角形
		{
			printf("此三角形是等边三角形\n");
		}
		else
			if(a==b ||a==c || b==c)                           //再判断三角形是否为等腰三角形
			{
				printf("此三角形是等腰三角形\n");
			}
			else
				if(a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a)    //判断三角形是否为直角三角形
				{
					printf("此三角形是直角三角形\n");
				}
				else
				{
					printf("此三角形为普通三角形\n");               //如果都不是则为普通三角形
				}
	}
	else
	{
		printf("此三边构不成三角形!!!\n");                  //三边不能构成三角形
	}
}

