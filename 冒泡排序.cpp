#include <stdio.h>

void Bob_sort(int a[],int n)
{
	int i,j;
	for(i=0;i<n-1;++i)
	{
		for(j=0;j<n-i-1;++j)
		{
			if(a[j]>a[j+1])
			{
				int tem=a[j];
				a[j]=a[j+1];
				a[j+1]=tem;
			}	
		}
	}
	for(i=0;i<n;++i)
	{
		printf("%d ",a[i]);
	}
}
int main()
{
	int a[]={1,2,321,42,53,675,21};
	int n=sizeof(a)/sizeof(a[0]);

	Bob_sort(a,n);
	
	return 0;
}
