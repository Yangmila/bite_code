#include <iostream>  
#include <iomanip.h> 
void main()   
{   double values[] = {1.23,35.36,653.7,4358.24};
    for(int i=0;i<4;i++)
    {   cout.width(10);
        cout.fill('*');
    cout << values[i] <<'\n';
  }
}

