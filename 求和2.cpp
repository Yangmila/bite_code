#include <stdio.h>
#include <math.h>
int main( )
{
	int N,i;
	double sum;
	scanf("%d",&N);
	for(i=0;i<N;i++)
	sum+=pow(-1,i)*(1.0/(1+i*3));
	printf("sum = %.3f",sum);
}
