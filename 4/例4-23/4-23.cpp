#include <iostream.h>

int i(10);
static next(int),last(int),other(int);
int reset();
void main()
{
    int i=reset();
    for(int j(1);j<=3;j++)
    {
        cout<<i<<","<<j<<",";
        cout<<next(i)<<",";
        cout<<last(i)<<",";
        cout<<other(i+j)<<endl;
    }
}

static int next(int j)
{
    j=i++;
    return j;
}
static int last(int j)
{
    static int i(20);
    j=i--;
    return j; 
}
static int other(int i)
{
    int j(15);
    return i=j+=i;
}