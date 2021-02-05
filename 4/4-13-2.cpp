#include <iostream.h>
inline int f(int x)
{	return x*x;}
void main()
{
	int x(2);
	cout<<f(x)<<endl;
	cout<<f(x+1)<<endl;
}
