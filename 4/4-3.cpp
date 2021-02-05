#include <iostream.h>
template <class Stype>
void swap1(Stype & x,Stype & y)
{
    Stype temp;
    temp=x;
    x=y;
    y=temp;
    cout<<"x="<<x<<", "<<"y="<<y<<endl;
}
void main()
{
    int a(5),b(9);
	float m,n;
	cin>>m>>n;

    swap1(a,b);
    cout<<"a="<<a<<", "<<"b="<<b<<endl;
	cout<<"m="<<m<<", "<<"n="<<n<<endl;
	swap1(m,n);
    cout<<"m="<<m<<", "<<"n="<<n<<endl;
}
