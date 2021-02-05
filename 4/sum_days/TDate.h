int IsLeapYear(int year)
{	return (year%4==0 && year%100!=0)||(year%400==0); }
int sum_days(int year,int month,int day,int *month_days)
{
	int sum=0;
	for(int i=1;i<month;i++)
		sum=sum+month_days[i];
	sum=sum+day;
	if(IsLeapYear(year)&&month>2) sum=sum+1;
	return sum;
}
