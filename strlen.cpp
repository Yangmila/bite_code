#include <stdio.h>

int strlen(char *a)
{
	if(*a!='\0')
	{
		return 1+strlen(a+1);
	}
}

int nostrlen(char *a)
{
	int count=0;
	
	while(*a!='\0')
	{
		count++;
		a++;
	}

	return count;
}
int main()
{
 	char a[]="hkdiausaod";
 	int count,count1;
 	
 	count1=strlen(a);
 	count=nostrlen(a);
 	printf("�ݹ��ַ�������Ϊ��%d\n",count1);
 	printf("�ǵݹ��ַ�������Ϊ��%d",count);
 	 
 	return 0;
} 
