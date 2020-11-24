#include<stdio.h>
#include<assert.h>
char *my_strstr(const char *hay, const char *need)
{
	assert(hay!=NULL&need!=NULL);
	const char *phay=hay;
	const char *start=need;
	const char *pneed=need;
	
	while(*start != '\0')
	{
		phay=start;
		pneed=need;
		
		while(*phay!='\0'&&*pneed!='\0')
  		{
			if(*phay==*pneed)
			{
				*phay++;
				*pneed++;
			}
			else
				break;
		}
		if(*phay=='\0')
			return start;
		start++;	
	}
	
	return NULL;
	
}
int main()
{
	char str1[20]="asdfghj";
	char str2[20]="dfgh";
	char *ret=my_strstr(str1,str2);
	
	printf("×Ó×Ö·û´®Îª£º%s\n",ret);
}
