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
		printf("%d�������ꡣ",year);
	}
	else
	{
		printf("%d�겻�����ꡣ",year);
	}
	
	return 0;
 } 
