#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
void main()
{
    ifstream infile;
    infile.open("f1.dat",ios::in);
    if(!infile)
    {
      cout<<"f1.dat can't open.\n";
      abort();
    }
    char s[80];
    while(!infile.eof())
    {
      infile.getline(s,sizeof(s));
      cout<<s<<endl;
    }
    infile.close();
}
