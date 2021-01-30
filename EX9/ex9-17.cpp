#include <iostream.h>
#include <iomanip.h>
void main()
{
    cout<<"12345678901234567890"<<endl;
    int  i=1234;
    cout<<i<<endl;
    cout<<setw(12)<<i<<endl;
    cout<<resetiosflags(ios::right)<<setiosflags(ios::left)
              <<setfill('*')<<setw(12)<<i<<endl;
    cout<<resetiosflags(ios::left)<<setiosflags(ios::right)
              <<setprecision(5)<<setw(12)<<12.3456789<<endl;
    cout<<"width:"<<cout.width()<<endl;
}