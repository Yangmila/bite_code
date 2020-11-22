#include<stdio.h>

void chengfa(int n)
{
	int i,j,result;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)
		{
			result=i*j;
			printf("%d*%d=%d\t",j,i,result);
		}
		printf("\n");
	}
		
}
int main()
{
	int n;
	
	scanf("%d",&n);
	chengfa(n);
	
	return 0;
 } 
