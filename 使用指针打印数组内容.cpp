#include<stdio.h>
int main()
{
	int a[]={2,23,34,53,54,76,87,98};
	int n=sizeof(a)/sizeof(a[0]);
	int *p=a;
	int i;
	
	for(i=0;i<n;++i)
	{
		printf("%d ",*(p+i));
	} 
	
	return 0;
 } 
