#include <iostream.h>
int add(int x,int y)
{
    return x+y;
}
void main()
{
    int x(4),y(6);
    int z=add(++x,x+y);
    cout<<z<<endl;
}
