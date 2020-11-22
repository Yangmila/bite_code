#include <stdio.h>

void Swap(int *a, int n)
{
	int i;
	int *low=a;
	int *high=a+n-1;
	while(low<high)
	{
		while(low<high&&(*low&1))
		{
			low++;
		}
		while(low<high&&(!(*high&1)))
		{
			high--;
		}
		if (low<high)
		{
			*low^=*high;
			*high^=*low;
			*low^=*high;
        low++;
		high--;
	   }
	}
		
	for (i=0;i<n;i++)
		printf("%d ", a[i]);
}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10 };
	int n = sizeof(a) / sizeof(a[0]);
	
	Swap(a,n);
	
	return 0;
}
