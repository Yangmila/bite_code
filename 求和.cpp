#include<stdio.h>
int Sn(int m)
{
	int i;
	int add=0,Sum=0;
	for(i=0;i<5;++i)
	{
		add=add*10+m;
		Sum=Sum+add;
	}
	return Sum;
}
int main()
{
	int m;
	int ret;
	
	scanf("%d",&m);
	ret=Sn(m);
	printf("Sum=%d",ret);
	
	return 0;
}
