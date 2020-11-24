/*
#include<stdio.h>
#include<assert.h>

char * my_strcat(char * dest, const char * src)
{
	assert(dest != NULL && src != NULL);
	char *pdest = dest;
	const char *psrc = src;

	while (*pdest != '\0')
	{
		*pdest++;
	}
	while (*psrc != '\0')
	{
		*pdest++ = *psrc++;
	}
	*pdest = '\0';
	return dest;
}
int main()
{
	char str1[20] = "Hi";
	char *str2 = "Word!";
	printf("str1 = %s\n", str1);

	char *pret = my_strcat(str1, str2);
	printf("str1 = %s\n", pret);
}*/