#include<stdio.h>

void tower(int n,char a,char b,char c);
void move(char x,int n,char y);

int count=0;

int main()
{
	int n;
	if(scanf("%d",&n)==1)
	{
		tower(n,'a','b','c');
	}
	else
	{
		printf("ERROR\n");
	}
		printf("%d",count);
	return 0;
}

void tower(int n,char x,char y,char z)
{
	if(n==1)
	{
		move(x,n,z);
	}
	else
	{
		tower(n-1,x,z,y);
		move(x,n,z);
		tower(n-1,y,x,z); 
	}
}

void move(char x,int n,char y)
{
	count++;
}
