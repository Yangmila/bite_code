#include <stdio.h>

void print(int n)
{
	if(n<10)
		printf("%d",n);
	else
		{
			print(n/10);//�ȵݹ���ӡ������������ȴ�ӡ��ݹ飬������� 
			printf(" %d",(n%10));
		}
}
int main()
{
	int n;
	printf("����һ��������");
	scanf("%d",&n);
	print(n);
	
	return 0;
}
