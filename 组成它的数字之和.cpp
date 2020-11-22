#include <stdio.h>

int DigitSum(int n)
{
	int sum=0;
	int m=0;
	if(n!=0)
	{
		m=n%10;
		n=n/10;
		sum=m+DigitSum(n);
	}
	return sum;
}
int main()
{
	int n,ret;
	scanf("%d",&n);
	ret=DigitSum(n);
	printf("组成它的数字之和为：%d",ret);
	
	return 0;
}
