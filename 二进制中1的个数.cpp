#include <stdio.h>
int Num(int m)
{
	int ret;
	int i=31;
	int count=0;
	
	while (i>=0)
	{
		ret=(m >> i) & 1;
		if(ret==1)
		{
		 	count++;
		}
		i--;
	}
	
	return count;
}
int main()
{
	int m,ret;
	scanf("%d",&m);
	int i = 31;
	
	printf("二进制：");
	while (i>=0)
	{
		printf("%d ", (m >> i) & 1);
		i--;
	}
	printf("\n");
	
	ret=Num(m);	
	
	printf("二进制中 1 的个数为：%d",ret);
	
	return 0;
}
