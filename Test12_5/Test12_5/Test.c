#include<stdio.h>

#define MAX(a, b) ( (a) > (b) ? (a) : (b) )

void main()
{
	int x = 5;
	int y = 8;
	int z = MAX(x+1, y+1);   // int z = ( (x++) > (y++) ? (x++) : (y++) )
	printf("x=%d y=%d z=%d\n", x, y, z);
}

/*
//  #   ##

#define MY_STRUCT(name)\
struct struct_##name\
{\
	int a;\
	int b; \
	int c;\
}
/////////////////////////////////////////////////

MY_STRUCT(wn);  //struct_wn
MY_STRUCT(bss); //struct_bss;
void main()
{
	struct struct_wn wn; 

}

/*
#define SQUARE(x) printf(#x "*" #x "= %d\n", x * x)

void main()
{
	SQUARE(5);
}

/*
//续行符
#define PRINT(FORMAT, VALUE) printf("the value is "FORMAT"\n", VALUE);

void main()
{
	PRINT("%d", 10);
	//printf("%s", MY_STR);
}

/*
void main()
{
	char* p = "hello "    "bit " "Linux\n";
	printf("hello" " bit\n");
	//printf("%s", p);
}

/*
#define MAX 100


void main()
{
	int max = MAX;  //int max = MAX;;

	int a = 10;
	if(a == 10)
		max = MAX; //int max = MAX;;
	else
		a = 0;
}

/*
//日志

void Log(char *file, int line, char *msg)
{
	printf("Log: %s : %d : %s : %s  : %s\n", file, line, __DATE__, __TIME__, msg);
}

#define LOG(msg) Log(__FILE__, __LINE__, msg);

 void main()
 {
	 FILE *fp = fopen("Test1.txt", "r");
	 if(fp == NULL)
	 {
		 LOG("Open File Error.");
		 return;
	 }

	 LOG("Open File OK.");


 }

/*
void Log(char *msg)
{
	printf("Log: %s : %d : %s : %s  : %s\n", __FILE__, __LINE__, __DATE__, __TIME__, msg);
}

 void main()
 {
	 FILE *fp = fopen("Test.txt", "w");
	 if(fp == NULL)
	 {
		 Log("Open File Error.");
		 return;
	 }

	 Log("Open File OK.");


 }

/*
void main()
{
	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	//printf("%s\n", __STDC__);
}

/*
void main()
{
	while(1)
	{
		printf("Hello Bit.\n");
	}

}
*/