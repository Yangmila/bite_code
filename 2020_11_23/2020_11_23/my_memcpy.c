/*
#include<stdio.h>
#include<assert.h>

void * my_memcpy(void * dest, const void * src, size_t num)
{
	assert(dest != NULL && src != NULL);
	char *pdest = (char*)dest;
	const char *psrc = (const char*)src;

	while (num-- > 0)
	{
		*pdest++ = *psrc++;
	}
	return dest;
}
int main()
{
	char str[20] = "ghfjkhkj";

	printf("str = %s\n", str);
	my_memcpy(str, str + 3, 4);

	printf("str = %s\n", str);
}
*/