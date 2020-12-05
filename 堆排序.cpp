#include<stdio.h>
#include<math.h>

int c=0;

void heapAdjust(int a[], int s, int m)
{
    int key = a[s];
    for(int j = 2*s + 1; j <= m; j = 2*j + 1 )
	{
        if(j < m && a[j] <= a[j+1] ) ++j;
        if( a[j] <= key ) break;
        a[s] = a[j];
        s = j;
    }
    a[s] = key;
}

void swap(int a[], int i, int j) 
{ 
  	int temp; 
  	temp=a[i]; 
  	a[i]=a[j]; 
  	a[j]=temp; 
  	c++; 
} 
  
void heap_sort(int a[], int size)
{
    for(int i = size/2-1; i >= 0; --i)
	{
        heapAdjust(a, i, size-1);
    }
    for(int i = size-1; i > 0 ; --i)
	{
        swap(a, 0, i);
        heapAdjust(a, 0, i-1);
    }
    
}


int main( )
{
	int n, i;
	scanf("%ld", &n);
	long N=2*pow(10,5);
	int a[N];
	
	for(i=0; i<n; i++)
	 scanf("%d", &a[i]);

	heap_sort(a, n);

	for(i=0; i<n; i++) printf("%d ", a[i]);
	return 0;
}
