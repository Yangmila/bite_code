#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int i,n;
	for(n=2;n<=100;n++)
	{
		for(i=2;i<=(int)(sqrt(n));i++)
		{
			if(n%i==0)
				break;
		}
		if(i>(int)(sqrt(n)))
		{
			cout<<n<<" ";
		}
	 } 
		cout<<endl;
} 
