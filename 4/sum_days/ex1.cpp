#include  <iostream.h>
#include "TDate.h"
int month_days[13]
={0,31,28,31,30,31,30,   31,31,30,31,30,30};
void main()
{
	cout<<"请输入年月日(yyyy mm dd):";
	int year,month,day; 
	cin>>year>>month>>day;
	
	cout<<year<<"年"<<month<<"月"<<day<<"日"<<"是本年的";
	cout<<sum_days(year,month,day,month_days)<<"天。"<<endl;
}