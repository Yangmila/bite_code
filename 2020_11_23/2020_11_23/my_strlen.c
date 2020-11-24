#include<stdio.h>
#include<assert.h>

size_t my_strlen(const char *string)
{
	assert(string != NULL);
	const char *pstr = string;
	size_t count=0;

	while (*pstr++ != '\0')
	{
		count++;
	}
	return count;
}

int main()
{
	char *str1 = "hello";

	int ret = my_strlen(str1);
	printf("len=%d\n",ret);
}