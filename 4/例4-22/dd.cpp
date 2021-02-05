#include <iostream.h>
extern int i;
void fun3()
{
    i=30;
    cout<<"fun3():i(extern)="<<i<<endl;
	if(i)
	{
		int i=10;
		cout<<"fun3():i(auto)="<<i<<endl;

	}
}