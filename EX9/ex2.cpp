#include <iostream>  
#include <iomanip.h> 
void main()   
{ double values[]={1.23,35.36,653.7,4358.24};
  char *names[]={"Zoot","Jimmy","Al","Stan"};
  cout<<setiosflags(ios::scientific);
  for(int i=0;i<4;i++)
    cout<<setiosflags(ios::left)<<setw(6)<<names[i]
       <<resetiosflags(ios::left)<<setw(10)<<setprecision(2)
       << values[i]<<endl;}


