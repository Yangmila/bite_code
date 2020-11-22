#include<stdio.h>
int main()
{
	int a[]={1,2,321,42,53,675,21};
	int b[]={21,3,43,54,78,98,65};
	int n=sizeof(a)/sizeof(a[0]);
	int n1=sizeof(b)/sizeof(b[0]);
	int i,j;
	for(i=0;i<n;i++)
	{
		int temp;
		temp=a[i];
		a[i]=b[i];
		b[i]=temp;	
	}
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
	for(j=0;j<n1;++j)
	{
		printf("%d ",b[j]);
	}
	return 0;
}
