#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>
void main()
{
    fstream outfile,infile;
    outfile.open("f3.dat",ios::out);
    if(!outfile)
    {
      cout<<"f3.dat can,t open.\n";
      abort();
    }
    char str[]="this is a C++ program.";
    for(int  i=0;i<=strlen(str);i++)
        outfile.put(str[i]);
    outfile.close();
    infile.open("f3.dat",ios::in);
    if(!infile)
    {
      cout<<"f3.dat can't open.\n";
      abort();
    }
    char ch;
    while(infile.get(ch))
      cout<<ch;
    cout<<endl;
    infile.close();
}
