
#include<stdio.h>
#include<assert.h>
char *my_strncat(char *Dest, const char *Src, size_t count)
{
	assert(Dest != NULL&&Src != NULL);
	char *pdest = Dest;
	const char *psrc = Src;

	while (*pdest != 0)
	{
		pdest++;
	}

	while (count-- > 0)
	{
		*pdest= *psrc;
		pdest++;
		psrc++;
	}
	*pdest = '\0';
	return Dest;
}
int main()
{
	char str1[20] = "asdfg";
	char *str2 = "qwert";
	printf("str1 = %s\n", str1);
	char *pret=my_strncat(str1, str2, 5);
	printf("str1 = %s\n", pret);

}
