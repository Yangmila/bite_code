#include<stdio.h>
#include<assert.h>
char cpy(char *a,char *b)
{
 	assert(a != NULL && b != NULL);
 	while (*b!= '\0') 
	{
		*a++ = *b++;
	}
		*a = '\0';
}
int main()
{
	char a[]="asjakd";
	char b[]="hfdjdgw";
	cpy(a,b);
	printf("���ƺ���ַ���Ϊ��%s",a);
	return 0;
}
