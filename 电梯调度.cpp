#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int *Init(int arr[])
{
	int i = 0;
	srand((unsigned int)time(0));

	for (i = 0; i < 16; i++)
	{
		arr[i] = rand() % 200 + 1;
		printf("%d ", arr[i]);
	}

	printf("\n");
	return arr;

}

void two_part(int arr[])
{
	int i = 0;
	int j = 0;
	int k = 0;
	int sum = 0;
	int a[16];
	int b[16];
	int num = 100;      //��ǰ��ͷ��100�Ŵŵ���

	a[0] = 100;
	b[0] = 100;

	for (i = 0; i < 16; i++)
	{
		for (j = 1; j < 16 - i; j++)
		{
			if (arr[j] < arr[j - 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
	i = 0;
	j = 0;

	for (i = 0; i < 16; i++)
	{
		if (arr[i] >= num)
		{
			a[j+1] = arr[i];
			j++;
		}
		else
		{
			b[k+1] = arr[i];
			k++;
		}
	}

	printf("�������У�\n");

	for (i = 1; i <= j; i++)
	{
		printf("%d ", a[i]);
	}

	for (i = k; i >0; i--)
	{
		printf("%d ", b[i]);
	}

	sum = ((a[j]-100)*2+(100- b[1]))/16;
	printf("ƽ��Ѱ�����ȣ�%d", sum);
}

int main()
{
	int arr[16] = { 0 };
	int *ret=Init(arr); 
	two_part(ret);
	getchar();
	return 0;

}
