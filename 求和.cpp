#include <math.h>
#include <iostream>
#include <stdio.h>
using namespace std;
int fact(int n)
{
	if(n!=0)
	return n*fact(n-1);
	else 
	return 1;
}
int main( )
{
	double sum=1,eps,n;
	int i=1,a,b;
	scanf("%le", &eps);
	while(1)
	{
		a=fact(i);
		b=(2*i)+1;
		n=(double)a/b;
		if(n<eps) break;

			sum+=n;
			i++;	
	}
	
	printf("Pi = %.5f",2.0*sum);
	return 0;
}
