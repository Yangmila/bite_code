#include<stdio.h>
int NoFib(int n)
{
	int a=1;
	int b=1;
	int c=0;
	while(n>2)
	{
		c=a+b;
		a=b;
		b=c;
		n--;
	}
	return b;
}

int Fib(int n)
{
	if(n==1)
		return 1;
	if(n==2)
		return 1;
	else
		return Fib(n-1)+Fib(n-2);
		
}
int main()
{
	int n,ret,ret1;
	scanf("%d",&n);
	ret=Fib(n);
	ret1=NoFib(n); 
	printf("递归输入：%d,输出:%d\n",n,ret);
	printf("非递归输入：%d,输出:%d\n",n,ret1);
}
