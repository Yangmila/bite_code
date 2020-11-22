#include<stdio.h>

int main()
{
	int m,n,ret;
	
	printf("输入两个整数：");
	scanf("%d %d",&m,&n);
	m=m^n;
	n=m^n;
	m=m^n;
	printf("结果为：%d %d",m,n);
	
	return 0;
}
