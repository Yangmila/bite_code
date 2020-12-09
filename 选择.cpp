#include<stdio.h>
#define N 10000 

void select_sort(int a[], int n)
{ 
	int i,j,max,t;
	for( i = 0; i < n-1; i++)
	 { 
 		max = i;
    	for( j = i; j < n; j++)
		  { 
			 if(a[j] > a[max]) max = j; 
				} 
				if( max != i)
				  { 
 					t = a[i]; 
          			a[i] = a[max]; 
					a[max] = t; 
				    } 
      	} 
}


int main( )
{
	int n, i;
	scanf("%d", &n);
	
	int a[N];
	
	for(i=0; i<n; i++)
	 scanf("%d", &a[i]);

	select_sort(a,n);

	for(i=0; i<n; i++) printf("%d ", a[i]);
	return 0;
}
