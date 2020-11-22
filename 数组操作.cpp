#include<stdio.h>
void init(int a[],int n)
{
	int i;
	for(i=0;i<n;++i)
	{
		a[i]=0;
	}

}
void print(int a[],int n)
{
	int j;
	for(j=0;j<n;++j)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
} 
void reverse(int a[],int n) 
{
	int low=0;
	int high=n-1;
	while(low<high)
	{
		int tem=a[low];
		a[low]=a[high];
		a[high]=tem;
		low++;
		high--;
	}
}
void Show(int arr[], int sz)   
{
 	int i = 0;
 	for (i = 0; i < sz; i++)
 	{
  		printf("%d ", arr[i]);
 	}
 	printf("\n");
}
int main()
{
	int a[]={1,2,321,42,53,675,21};
	int n=sizeof(a)/sizeof(a[0]);
 	init(a,n); 
	Show(a,n);   
 	//print(a,n);        
 	//reverse(a,n);  
 	//Show(a,n);	

	return 0;
}
