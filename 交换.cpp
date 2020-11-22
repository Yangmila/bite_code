#include <stdio.h> 

void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

int main()
{
	int a,b;
	
	printf("输入两个数:");
	scanf("%d %d",&a,&b); 
	swap(&a,&b);
	printf("%d %d",a,b);
	
	return 0;
}
