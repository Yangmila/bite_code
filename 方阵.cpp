#include <stdio.h>
#define N 6
int main(){
	int i,j,n,k,a[N][N],max,min,sum=0;
	
	printf("Intput:");
		
	scanf("%2d",&n);
		printf("\n");
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			a[i][j]=i*n+j+1;
			printf("%2d",a[i][j]);		
		}
		printf("\n");
		
	}
		printf("\n");

		for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++){
			a[i][j]=i*n+j+1;
			printf("%2d",a[j][i]);		
		}
		printf("\n");
	}	
	printf("\n");
			
	max=a[0][0];
	min=a[0][0];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(max<a[i][j])max=a[i][j];
			if(min>a[i][j])min=a[i][j];
			sum+=a[i][j];
		} 
		
	}
	printf("��������ֵ=%d,��Сֵ=%d,����Ԫ�صĺ�=%d \n\n",max,min,sum);
	
	
	max=a[0][0];
	min=a[0][0];
	sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(max<a[i][j])max=a[i][j];
			if(min>a[i][j])min=a[i][j];
			sum+=a[i][j];
		}
		printf("��%d�е����ֵ=%d,��Сֵ=%d,����Ԫ�صĺ�=%d \n",i+1,max,min,sum);
		sum=0;max=a[i][0];min=a[i+1][0]; 
	}
	printf("\n");
	
	max=a[0][0];
	min=a[0][0];
	sum=0;
	for(j=0;j<n;j++)
	{
		for(i=0;i<n;i++)
		{
			if(max<a[i][j])max=a[i][j];
			if(min>a[i][j])min=a[i][j];
			sum+=a[i][j];
		}
		printf("��%d�е����ֵ=%d,��Сֵ=%d,����Ԫ�صĺ�=%d \n",j+1,max,min,sum);
		sum=0;max=a[0][j];min=a[0][j+1]; 
	}
	printf("\n");
	
	sum=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)sum+=a[i][j];
		}
	}
	printf("���Խ���Ԫ�صĺ�=%d \n",sum);
	printf("\n");
	
	sum=0;
	k=n-1;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i+j==k)sum+=a[i][j];
		}
	}
	printf("���Խ���Ԫ�صĺ�=%d \n",sum);
	printf("\n");
}


	

