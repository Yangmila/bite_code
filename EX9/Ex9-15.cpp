#include <iostream.h>
void main()
{
    cout.setf(ios::oct,ios::basefield);
    cout<<"OCT:48-->"<<48<<endl;
    cout.setf(ios::dec,ios::basefield);
    cout<<"DEC:48-->"<<48<<endl;
    cout.setf(ios::hex,ios::basefield);
    cout<<"HEX:48-->"<<48<<endl;
    cout.setf(ios::showbase);
    cout<<"HEX:32-->"<<32<<endl;
    cout.setf(ios::uppercase);
    cout<<"HEX:254-->"<<254<<endl;
}