#include<stdio.h>
int main()
{
	int j;
	int n;
	int x;
	int num;
	int nums = 0;
	scanf("%d",&n);
	
	for(int i = 0;i < n;i ++)
	{
		scanf("%d",&x);
		for(j = 0;j < x;j ++)
		{
			scanf("%d",&num);
			nums += num;
		}
			printf("%d\n",nums);
			nums = 0;
		}
}
