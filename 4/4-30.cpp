#include <iostream.h>
template <class T>
T max (T a, T b)
{
  return a>b? a: b;
}
void main()
{
  int n1=8, n2=9;
  double m1=3.14, m2=3.15;
  char c1='m', c2='n';
  cout<<"max(n1, n2)="<<max(n1, n2)<<endl;
  cout<<"max(m1, m2)="<<max(m1, m2)<<endl;
  cout<<"max(c1, c2)="<<max(c1, c2)<<endl;
}
