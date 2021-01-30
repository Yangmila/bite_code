#include <fstream.h>
#include <iostream.h>
void main()
{  
	ofstream ostrm;
    
	ostrm.open("C:\\aa\\f1.dat");
	ostrm<<120<<endl;
    ostrm<<'M'<<endl;    
	ostrm<<310.85<<endl;
    ostrm.close();
    
	ifstream istrm("C:\\aa\\f1.dat");
    int a;  char n;    double d;
    istrm>>a>>n>>d;
    cout<<a<<","<<n<<","<<d<<endl;
    istrm.close();
}
