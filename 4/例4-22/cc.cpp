#include <iostream.h>
void fun2()
{
    int i=15;
    cout<<"fun2():i(auto)="<<i<<endl;
	if(i)
	{
		extern int i;
		cout<<"fun2():i(extern)="<<i<<endl;

	}
}