#include <iostream.h>
void main()
{
    int a(5),b(7),c(10);
    cout<<a<<", "<<b<<", "<<c<<endl;
    {
        int b(8);
        float c(8.8);
        cout<<a<<", "<<b<<", "<<c<<endl;
        a=b;
        {
            int c;
            c=b;
            cout<<a<<", "<<b<<", "<<c<<endl;
        }
    cout<<a<<", "<<b<<", "<<c<<endl;
    }
    cout<<a<<", "<<b<<", "<<c<<endl;
}
