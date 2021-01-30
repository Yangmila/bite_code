#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
void main()
{
    ofstream outfile;
    outfile.open("f2.dat",ios::out);
    if(!outfile)
    {
        cout<<"f2.dat can't open. "<<endl;
        abort();
    }
    outfile<<"this is a program. "<<endl;
    outfile.close();}

