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
	
	printf("��������������");
	scanf("%d %d",&m,&n);
	ret=Dif(m,n);
	printf("�����Ʊ���У���%d��λ��ͬ",ret);
	
	return 0;
 } 
