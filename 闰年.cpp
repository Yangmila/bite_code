#include<stdio.h>
int Leap_year(int year)
{
	if((year%4==0)&&(year%100!=0)||(year%400==0))
	{
		return 1;
	}
	else
		return 0;	
}

int main()
{
	int year;
	scanf("%d",&year);

	if(Leap_year(year)==1)
	{
		printf("%d年是闰年。",year);
	}
	else
	{
		printf("%d年不是闰年。",year);
	}
	
	return 0;
 } 
