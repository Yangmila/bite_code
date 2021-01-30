#include <iostream.h>
void main()
{
    int  i=4321;    
    cout.width(10);  cout<<i<<endl;
    cout.width(10);  cout.fill('*');  cout.setf(ios::left,ios::adjustfield);
    cout<<i<<endl;
    cout.width(10);  cout.setf(ios::right,ios::adjustfield);  cout.precision(6);
    double  j=12.3456789;
    cout<<j<<endl;
 }
