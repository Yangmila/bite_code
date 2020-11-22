#include <stdio.h>
int Dif(int m,int n)
{
	int i;
	int count=0;
	int tmp=m^n;
	while (tmp)
    {
        tmp = tmp & (tmp - 1);
        count++;
    }
	return count;
}
int main()
{
	int m,n,ret;
	
	printf("输入两个整数：");
	scanf("%d %d",&m,&n);
	ret=Dif(m,n);
	printf("二进制表达中，有%d个位不同",ret);
	
	return 0;
 } 
