#include <iostream.h>
typedef int array[8];
int a[8]={1,3,5,7,9,11,13};
void fun(array &b,int n)
{    for(int i=0;i<n-1;i++)        b[7]+=b[i];  }
void main()
{    int m=8;
      fun(a,m);
      cout<<a[7]<<endl;
}
