#include<stdio.h>
struct B
{
	int a;
	short b;
	char c;
	int d;
	
}B;
void main()
{
	printf("%d\n", sizeof(B));

}
//8��C++���ǣ�c���Ի���32��
/*
typedef struct Test
{
	short a;//2+6
	struct t//�������֣���������͡���ռ�ռ䣨C++���ǣ�c���Ի���32��
	{
		double c;//8  �Ƴ�Ա
		int b;//4
		char d;//1+3
	};
	int e;//4+4
}Test;

void main()
{
	printf("%d\n", sizeof(Test));

}
//32
typedef struct Test
{
	short a;//2+6
	struct
	{
		double c;//8
		int b;//4
		char d;//1+3
	};
	int e;//4+4
}Test;

void main()
{
	printf("%d\n", sizeof(Test));

}*/
/*
#pragma pack(2)
typedef struct Test
{
	short a;//2
	struct
	{
		int b;//4
		double c;//8
		char d;//1+1
	};
	int e;//4
}Test;

void main()
{
	printf("%d\n", sizeof(Test));

}*/
/*
typedef struct Test
{
short a;//2+6
struct
{
int b;//4+4
double c[10];//80
char d;//1+7
};
int e;//4+4
}Test;


typedef struct Test
{
	short a;//2+6
	struct
	{
		int b;//4+4
		double c;//8
		char d;//1+7
	};
	int e;//4+4
}Test;*/