#include<stdio.h>
#include<math.h>

void merge(int a[], int low, int mid, int high){
    int i,j,k,m;
	int t[high-low+1];
    i = mid;
 	j = high;
	m = high - low;
    while( i>=low && j >= mid+1 ){
        if(a[i] > a[j]) 
			t[m--] = a[i--];
        else 
			t[m--] = a[j--];
    }
    while(i >= low ) t[m--] = a[i--];
    while(j >= mid+1) t[m--] = a[j--];
    for( k = low; k <= high; ++k){
        a[k] = t[k-low];
    }
}

void merge_sort(int a[], int low, int high){
    if( low >= high) return;
    int mid = (low + high)/2;
    merge_sort(a, low, mid);
    merge_sort(a, mid+1, high);
    merge(a, low, mid, high);
}


int main( )
{
	int n, i;
	scanf("%ld", &n);
	long N=2*pow(10,6);
	int a[N];
	
	for(i=0; i<n; i++)
	 scanf("%d", &a[i]);

	merge_sort(a, 0, n-1);

	for(i=0; i<n; i++) printf("%d ", a[i]);
	return 0;
}

