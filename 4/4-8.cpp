#include <iostream.h>
void fun(int a=1,int b=3,int c=5)
{
    cout<<"a="<<a<<", "<<"b="<<b<<", "
           <<"c="<<c<<endl;
}
void main()
{
    fun();
    fun(7);
    fun(7,9);
    fun(7,9,11);
    cout<<"OK! "<<endl;
}
