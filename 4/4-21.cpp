#include <iostream.h>
void other();
void main()
{
   auto int a(3);
    register int b(5);
    static int c;
    cout<<"a="<<a<<","<<"b="<<b<<","<<"c="<<c<<endl;
    other();
    other();
}
void other()
{    
    int a(5);
    static int b(12);
    a+=10;
    b+=20;
    cout<<"a="<<a<<","<<"b="<<b<<endl;
}