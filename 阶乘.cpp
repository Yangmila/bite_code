#include<stdio.h>

int digui(int n)
{
	if(n==1)
		return 1;
	return n*digui(n-1);
}
int feidigui(int n)
{
	int i,result;
	for(i=1;i<=n;++i)
	{
		result*=i;
	}
	return (result);
}

int main()
{
	int n,result,result1;
	scanf("%d",&n);
	result1=digui(n); 
	result=feidigui(n);
	
	printf("�ݹ�%d�Ľ׳�Ϊ:%d\n",n,result1);
	printf("�ǵݹ�%d�Ľ׳�Ϊ:%d",n,result);
	return 0;
 } 
