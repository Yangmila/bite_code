/*#include<stdio.h>
#include<assert.h>


int my_strcmp(const char *string1, const char *string2)
{
	assert(string1 != NULL && string2 != NULL);
	char *pstring1 = string1;
	const char *pstring2 = string2;

	while (*pstring1 != '\0' || *pstring2 != '\0')
	{
		if (*pstring1 > *pstring2)
			return 1;
		if (*pstring1 < *pstring2)
			return -1;
		*pstring1++;
		*pstring2++;
	}
	if (*pstring1 == '\0')
		return -1;
	if (*pstring2 == '\0')
		return 1;
	return 0;
}
int main()
{
	char *str1 = "hello";
	char *str2 = "helro";

	int ret = my_strcmp(str1, str2);

	if (ret == 0)
		printf("str1 equal to str2\n");
	if (ret<0)
		printf("str1 less than str2\n");
	if (ret>0)
		printf("str1 greater than str2\n");
}*/