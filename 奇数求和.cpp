#include <stdio.h>
int main( )
{
	int N,i;
	double sum;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	sum+=(1.0/(2*i-1));
	printf("sum = %.6f",sum);
}
