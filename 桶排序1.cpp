#include<stdio.h>
#include<stdlib.h>
#define N 500000

void bucket_sort(int* arr, int length)
{
    int i,j,max_num=arr[0];
    int* bucket;
    for(i=1;i<length;i++)
	{
        if(arr[i]>max_num)
		{
            max_num=arr[i];
        }       
    }
    max_num++;  
    if(arr==NULL || length<=1)
	{
        return;
    }
    if((bucket = (int*)malloc(sizeof(int)*max_num))==NULL){return;}
    for(i=0;i<max_num;i++)
	{
        bucket[i]=0;   
    }
    for(i=0;i<length;i++)
	{ 
        bucket[arr[i]]+=1;   
    }
    for(i=0,j=0;i<max_num;i++)
	{
        while((bucket[i])>0)
		{  
            arr[j]=i;   
            j++;
            bucket[i]--;
        }
    }
    free(bucket);
    bucket = NULL;

}

int main( )
{
	int n, i;
	scanf("%d", &n);
	
	int a[N];
	
	for(i=0; i<n; i++)
	 scanf("%d", &a[i]);

	bucket_sort(a,n);

	for(i=0; i<n; i++) printf("%d ", a[i]);
	return 0;
}


