#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
struct person
{
    char name[20];
    double height;
    unsigned short age;
};      
struct person people[4]={ "Wang",1.65,25,   "Zhang",1.72,24,
                          "Li",1.89,21,  	"Hung",1.70,22};
void main()
{
    fstream infile,outfile;
    outfile.open("f5.dat",ios::out|ios::binary);
    if(!outfile)
    {
          cout<<"f5.dat can't open.\n";
          abort();
    }
    for(int i=0;i<4;i++)
          outfile.write((char *)&people[i],sizeof(people[i]));
    outfile.close();
    infile.open("f5.dat",ios::in|ios::binary);
    if(!infile)
    {
           cout<<"f5.dat can't open.\n";
		   abort();
    }
    for(i=0;i<4;i++)
    {
          infile.read((char *)&people[i],sizeof(people[i]));
          cout<<people[i].name<<"\t"<<people[i].height<<"\t"
                          <<people[i].age<<endl;
    }
    infile.close();
}
