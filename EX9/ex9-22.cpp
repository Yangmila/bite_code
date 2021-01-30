#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
void main()
{
    fstream infile,outfile;
    infile.open("f2.dat",ios::in);
    if(!infile)
    {
      cout<<"f2.dat can't open.\n";
      abort();
    }
    outfile.open("f4.dat",ios::out);
    if(!outfile)
    {
      cout<<"f4.dat can't open.\n";
      abort();
    }
    char ch;
    while(infile.get(ch))
      outfile.put(ch);
    infile.close();
    outfile.close();
}