#include<stdio.h>
int main()
{
	int m=0;
	int i;
	scanf("%d",&m);
	
	i = 31;
	printf("二进制：");
	while (i>=0)
	{
		printf("%d ", (m >> i) & 1);
		i--;
	}
	printf("\n奇数位：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	printf("\n偶数位：");
	for (i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (m >> i) & 1);
	}
	return 0;
}
