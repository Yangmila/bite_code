#include <iostream.h>
int min(int a,int b);
int min(int a,int b,int c);
int min(int a,int b,int c,int d);
void main()
{
    cout<<min(13,5,4,9)<<endl;
    cout<<min(-2,8,0)<<endl;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int min(int a,int b,int c)
{
    int t=min(a,b);
    return min(t,c);
}
int min(int a,int b,int c,int d)
{
    int t1=min(a,b);
    int t2=min(c,d);
    return min(t1,t2);
}
