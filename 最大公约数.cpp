#include<stdio.h>
int gys(int n,int m)
{
	int tmp,ret;
	
	if(n<m)
	{
		tmp=n;
		n=m;
		m=tmp;
	}
	ret=n%m;
	while(ret!=0)
	{
		n=m;
		m=ret;
		ret=n%m;
	}
	return m;
}
int main()
{
	int n,m,ret;
	
	scanf("%d %d",&n,&m);
	ret=gys(n,m);
	printf("最大公约数为：%d\n",ret);
	
	return 0;
 } 
