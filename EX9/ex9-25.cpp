#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
void main()
{
    struct student
    {
        char name[20];
        long number;
        double totalscord;
    }
	stu[5]={  "Ma",97001,85.72,		       "Li",97002,92.62,
			   "Hu",97003,89.25,		   "Yan",97004,90.84,
			   "Lu",97005,80.92
	};
	cout<<sizeof( struct student)<<endl;
    fstream file1;
    student one;
    file1.open("f7.dat",ios::out|ios::in|ios::binary);
    if(!file1)
    {
        cout<<"f7.dat can't open.\n";
        abort();
    }
    for(int i=0;i<5;i++)
        file1.write((char *)&stu[i],sizeof(student));
    file1.seekp(sizeof(student)*4);
    file1.read((char *)&one,sizeof(stu[i]));
    cout<<one.name<<"\t"<<one.number<<"\t"<<one.totalscord<<endl;
    file1.seekp(sizeof(student)*1);
    file1.read((char *)&one,sizeof(stu[i]));
    cout<<one.name<<"\t"<<one.number<<"\t"<<one.totalscord<<endl;
    file1.close();
}