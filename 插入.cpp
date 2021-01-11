#include<stdio.h>
#define N 10000 

void Insertion_sort(int a[], int n)
{ 
	int i,j,k;
	for(i = 1; i < n-1; i++)
	{ 
 		k = a[i]; 
 		j = i-1; 
		while( j >= 0 && a[j] > k ) 
		  {
		  	a[j+1] = a[j]; 
			j--; 
		  }
			a[j+1] = k; 
	} 
}

int main( )
{
	int n, i;
	scanf("%d", &n);
	
	int a[N];
	
	for(i=0; i<n; i++)
	 scanf("%d", &a[i]);

	Insertion_sort(a,n+1);

	for(i=0; i<n; i++) printf("%d ", a[i]);
	return 0;
}

