#include<stdio.h>
int sushu(int n)
{
	int i;
	for(i=2;i<n;++i)
	{
		if(n%i==0)
		return 0;
	}
	return 1;
}

int main()
{
	int n=0;
	for(n=100;n<=200;++n)
	{
		if(sushu(n)==1)
		{
			printf("%d ",n);
		}
	}
	
	return 0;
 } 
