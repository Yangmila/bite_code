#include<stdio.h>
#include<stdlib.h>
#define N 500000

int max(int a[], int n)
{
    int i, max;
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

void count_sort(int a[], int n, int exp)
{
    int output[n];             
    int i, buckets[10] = {0};

    for (i = 0; i < n; i++)
        buckets[ (a[i]/exp)%10 ]++;
    for (i = 1; i < 10; i++)
        buckets[i] += buckets[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[buckets[ (a[i]/exp)%10 ] - 1] = a[i];
        buckets[ (a[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        a[i] = output[i];
}

void radix_sort(int a[], int n)
{
    int exp;    
    int max1 ;
	max1 = max(a, n);   
    for (exp = 1; max1/exp > 0; exp *= 10)
        count_sort(a, n, exp);
}

int main( )
{
	int n, i;
	scanf("%d", &n);
	
	int a[N];
	
	for(i=0; i<n; i++)
	 scanf("%d", &a[i]);

	radix_sort(a,n);

	for(i=0; i<n; i++) printf("%d ", a[i]);
	return 0;
}
