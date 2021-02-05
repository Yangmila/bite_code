#include <iostream.h>
extern int i;
void fun1()
{
    i=50;
    cout<<"fun1():i(static)="<<i<<endl;
}