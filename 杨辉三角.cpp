#include<stdio.h>
#include<stdlib.h> 
int main()
{
	int n;
	int s=1;
	scanf("%d",&n);
	printf("1\n");
	for(int i=2;i<=n;s = 1,++i)
	{
		printf("1 ");
		for(int j=1;j<=i-2;++j)
		{
			s = (i - j) * s / j;
			printf("%d ",s); 
		}
		printf("1\n");
	}
}
