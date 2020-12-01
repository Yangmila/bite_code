#include<stdio.h>
#include<assert.h>
char *my_strncpy(char *Dest, const char *Src, size_t count)
{
	assert(*Dest != NULL&&*Src != NULL);
	char *pDest = Dest;
	const char *pSrc = Src;

	while (count--)
	{
			*pDest++=*pSrc++;
	}

	return Dest;
}
int main()
{
	char str1[20] = "asdfg";
	char *str2 = "qwert";
	printf("str1 = %s\n", str1);
	char *pret = my_strncpy(str1, str2, 4);
	printf("str1 = %s\n", pret);

}