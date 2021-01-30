#include <iostream.h>   
#include <iomanip.h> 
void main()   
{ double values[]={1.23,35.36,653.7,4358.24};
  char *names[]={"Zoot","Jimmy","Al","Stan"};
  cout<<setiosflags(ios::scientific);
  for(int i=0;i<4;i++)
  {
	  cout<<setiosflags(ios::left);
	  cout<<setw(6)<<names[i];
	  cout<<resetiosflags(ios::left);
       cout<<setw(10)<<setprecision(2);
       cout<< values[i]<<endl;
  }
}