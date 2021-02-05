#include <iostream.h>
template <class T>
T add(T x,T y);

void main()
{
	int a,b;
	cin>>a>>b;
    cout<<add(a,b)<<endl;
    cout<<add(5.0,10.5)<<endl;
}
template <class T>
T add(T x,T y)
{
   return x+y;
}

