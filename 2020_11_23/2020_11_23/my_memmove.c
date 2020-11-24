/*#include<stdio.h>
#include<assert.h>

void * my_memmove(void * dest, const void * src, size_t num)
{
	assert(dest != NULL && src != NULL);
	char *pdest = (char*)dest;
	const char *psrc = (const char*)src;

	if (psrc >= pdest || pdest >= psrc + num)
	{
		while (num-- > 0)
			{
				*pdest++ = *psrc++;
			}
	}
	else
	{
		psrc = psrc + num - 1;
		pdest = pdest + num - 1;
		while (num-- > 0)
		{
			*pdest-- = *psrc--;
		}
	}
	
	return dest;
}
int main()
{
	char str[20] = "qyuwhsjagf";

	printf("str = %s\n", str);
	my_memmove(str+3, str , 4);

	printf("str = %s\n", str);
}
*/