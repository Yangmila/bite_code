#include<stdio.h>

int main()
{
	int m,n,ret;
	
	printf("��������������");
	scanf("%d %d",&m,&n);
	m=m^n;
	n=m^n;
	m=m^n;
	printf("���Ϊ��%d %d",m,n);
	
	return 0;
}
