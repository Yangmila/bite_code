#include<stdio.h>
#include<assert.h>
void single(int a[], int n, int *x, int *y)
{
	assert(x);
	assert(y);
	int *px = x;
	int *py = y;

	int ret;
	int i; 
	int j;
	for ( i = 0; i < n; ++i)
	{
		ret ^= a[i];
	}

	int rut = 1;
	while (1)
	{
		if (ret&rut)
		{
			break;
		}
		else
		{
			rut <<= 1;
		}
	}

	*px = 0;
	*py = 0;
	for ( j = 0; j < n; ++j)
	{
		if (a[j] & rut)
		{
			*px ^= a[j];
		}
		else
		{
			*py ^= a[j];
		}
	}

}
int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 1, 2, 3, 4 };
	int n = sizeof(a) / sizeof(a[0]);
	int x;
	int y;

	single(a, n, &x, &y);

	printf("%d %d\n", x, y);
	return 0;
}
