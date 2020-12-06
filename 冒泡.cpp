#include<stdio.h>
#define N 10000 
int main()
{
    int n,m,flag;
	int a[N];
	int i,j,t;
    scanf("%d",&n);
    m=n;
    for(;n>0;n--)
	scanf("%d",&a[n]);
    for(i=1;i<=m;i++)
	{
        flag=0;
        for(j=1;j<=m-i;j++)
		{
            if(a[j]>a[j+1])
			{    
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;   
            flag=1; 
            }
        }
        if(flag==0)break;
    }
    for(n=1;n<=m;n++)
	printf("%d ",a[n]);
	
     return 0;
}

	

