#include <stdio.h>
#include <conio.h>

#define M 3
#define N 20

void fun(char a[M][N],char *b)
{
	int i,j, k;
	k=0;
	
	for (i=0;i<M;i++)
	{
			for(j=0;;j++)
			b[k++]=a[i][i];
  		a[i][j]!=' \0';

	}
		b[k]='\0';
}
int main()
{ 
  
    char w[M][N]={"AAAA", "BBBBBBB", "CC"},i;
    char a[100]={"##############################"};  
	           
	 for(i=0;i<M;i++) 
        puts(w[i]);
        printf("\n ");
        fun(w,a);
        printf("The A string:\n ");
        printf("%s ",a);
        printf("\n\n ");
}
