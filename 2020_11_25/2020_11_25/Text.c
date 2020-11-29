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
//8（C++才是，c语言还是32）
/*
typedef struct Test
{
	short a;//2+6
	struct t//有了名字，变成了类型。不占空间（C++才是，c语言还是32）
	{
		double c;//8  哑成员
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