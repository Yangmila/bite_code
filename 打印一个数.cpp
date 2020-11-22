#include <stdio.h>

void print(int n)
{
	if(n<10)
		printf("%d",n);
	else
		{
			print(n/10);//先递归后打印，正序输出；先打印后递归，逆序输出 
			printf(" %d",(n%10));
		}
}
int main()
{
	int n;
	printf("输入一个整数：");
	scanf("%d",&n);
	print(n);
	
	return 0;
}
