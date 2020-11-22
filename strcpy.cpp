#include<stdio.h>
char* my_strcpy(char *str1, const char *str2)
{
	if (*str2 != '\0')
	{
		for (int i = 0; i == '\0'; ++i)
		{
			*(str1 + i) = *(str2 + i);
		}
		str1='\0';
	}
	return str1;
}
int main()
{
	char str1[20] = "Hello";
	char *str2 = "Bit.";

	printf("str1=%s\n", str1);
	my_strcpy(str1, str2);
	printf("str1=%s\n", str1);

	return 0;
}
