#include<stdio.h>
#include<string.h>
void res(char *a)
{
	char *low=a;
	char *high=a+strlen(a)-1;
	char tmp;
	while(low<high)
	{
		tmp=*low;
		*low=*high;
		*high=tmp;
		low++;
		high--; 
	 } 
 } 
int main()
{
	char a[]="njdkjkja";
	
	printf("ԭ�ַ���Ϊ��%s\n",a);
	res(a);
	printf("�������ַ���Ϊ��%s",a);
	
	return 0; 
}
