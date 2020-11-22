#include <stdio.h>
#include<stdlib.h>
void reverse_string(char * string)
{
	if(*string=='\0')
	{
		return ;
	}
	reverse_string(string+1);
	printf("%c",*string);
}

int main()
{
	char string[]="hkdiausaod";
	reverse_string(string);
	
	return 0;
}
