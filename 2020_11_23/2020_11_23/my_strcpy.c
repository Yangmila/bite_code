/*#include<stdio.h>
#include<assert.h>

char *my_strcpy(char *strDest, const char *strSrc)
{
	assert(strDest != NULL && strSrc != NULL);
	char *Dest = strDest;
	const char *Src = strSrc;

	while (*Src != '\0')
	{
		*Dest++ = *Src++;
	}
	*Dest = '\0';

	return strDest;
}

int main()
{
	char str1[] = "hello";
	char *str2 = "hi";
	printf("str1=%s\n", str1);

	char *pret = my_strcpy(str1, str2);
	printf("str1=%s\n", pret);
}*/