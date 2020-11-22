#include<stdio.h>
int sqr(int n,int k)
{
	if (k==1)
		return n;
	else 
		return(n*sqr(n,k-1));
		 
}
int main()
{
	int n,k,ret;
	scanf("%d %d",&n,&k);
	ret=sqr(n,k);
	
	printf("%dµÄ%d´Î·½:%d",n,k,ret);
	return 0;
 } 
