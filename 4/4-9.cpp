#include <iostream.h>
int m(8);
int add_int(int x,int y=7,int z=m);
void main()
{
    int a(5),b(15),c(20);
    int s=add_int(a,b);
    cout<<s<<endl;
}
int add_int(int x,int y,int z)
{    return x+y+z;}
