#include<stdio.h>
void Search(int arr[][3],int *px,int *py, int num)
{
	int j = *py - 1;
	int i = 0;
	while (i < *px && j >= 0)
	{
		if (num > arr[i][j])
		{
			i++;
		}
		else if (num < arr[i][j])
		{
			j--;
		}
		else
		{
			*px = i;
			*py = j;
			return;
		}
	}
	*px = -1;
	*py = -1;
}

int main()
{
	int x = 3;
	int y = 3;
	int n;
	int arr[3][3] = { { 1, 2, 3 }, { 2, 3, 4 }, { 3, 4, 5 } };
	scanf("%d",&n);
	Search(arr,&x,&y,n);
	printf("得到该数字下标为<%d,%d>\n", x, y);
	return 0;
}

