#include  <iostream.h>
#include "TDate.h"
int month_days[13]
={0,31,28,31,30,31,30,   31,31,30,31,30,30};
void main()
{
	cout<<"������������(yyyy mm dd):";
	int year,month,day; 
	cin>>year>>month>>day;
	
	cout<<year<<"��"<<month<<"��"<<day<<"��"<<"�Ǳ����";
	cout<<sum_days(year,month,day,month_days)<<"�졣"<<endl;
}