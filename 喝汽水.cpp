#include<stdio.h>
#define P 1
#define K 2
int Empty(int n)
{
	int ret=n/K;
	int empty=n/K+n%K;
	if(empty>1)
	{
		return ret+Empty(empty);
	}
	else
		return ret;
}
int main()
{
	int money;
	scanf("%d",&money);
	int num=money/P;
	int sum=num+Empty(num);
	printf("��%dԪ��������%dƿ��ˮ",money,sum);
	
	return 0;
 } 
