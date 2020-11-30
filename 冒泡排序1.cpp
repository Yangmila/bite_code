#include<stdio.h>
int cmp(const void *x, const void *y)
{
	return (*(int *)x) - (*(int *)y);
}

void Swap(char *p1, char *p2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
		*p1++;
		*p2++;
	}
}

void sort(void *base, int size, int width) 
 {
	int i = 0;
	int j = 0;
	int ret = 0;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (cmp((char *)base + j*width, (char *)base + (j + 1)*width)>0)
			{
			Swap((char *)base + j*width, (char *)base + (j + 1)*width, width);
			}
		}
	}
}

int main()
{
	int arr1[] = { 1, 2, 4, 6, 3, 2 };
	qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]));
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("%d ", arr1[i]);
	}
	getchar();
	return 0;
}

