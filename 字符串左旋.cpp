#include <stdio.h>
#include <string.h>

void Left(char c[], int len, int n)	
{
    n = n%len;
	int j = 0;
	for (j=0; j<n; j++)
	{
		int i = 0;
		char tmp = c[0];
		for (i=0; i<len-1; i++)
		{
			c[i] = c[i+1];
		}
		c[i] = tmp;
	}
}

int main()
{
	char c[] = "ABCD";
	int n = 0;
	printf("�����ַ��ĸ���-> ");
	scanf("%d",&n);
	int len = strlen(c);
	printf("����ǰ��%s\n", c);
	Left(c, len, n);
	printf("������%s\n", c);
	return 0;
}


