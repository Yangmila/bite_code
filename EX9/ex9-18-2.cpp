#include <fstream.h>
#include <iostream.h>
void main()
{  
	ofstream ostrm;
	
	ostrm.open("f1.dat",ios::out|ios::binary);
    
	int a=120;  char ch2='N';	double f1=310.85;
	ostrm.write((char *)&a,sizeof(a));
	ostrm.write((char *)&ch2,sizeof(ch2));
	ostrm.write((char *)&f1,sizeof(f1));
    
	ostrm.close();

    ifstream istrm("f1.dat",ios::in|ios::binary);
    int b;  char ch4;    double f2;
	cout<<b<<","<<ch4<<","<<f2<<endl;
    istrm.read((char *)&b,sizeof(b));
	istrm.read((char *)&ch4,sizeof(ch4));
	istrm.read((char *)&f2,sizeof(f2));
    cout<<b<<","<<ch4<<","<<f2<<endl;
    istrm.close();
}
