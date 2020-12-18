#include<iostream>
#define P 3.1415926
using namespace std;
class TPool
{
	public:
		TPool(int a)
		{
			r=a;
		}
		void fence();
		void pass();
	private:
		float r;
};
void TPool::fence()
{
	float c;
	float price1;
	c=(r+3)*P*2;
	price1=c*35;
	cout<<"栅栏的造价为："<<price1<<"元"<<endl; 
}
void TPool::pass()
{
	float s;
	float price2;
	s=(r+3)*P*(r+3)-P*r*r;
	price2=s*20;
	cout<<"过道的造价为："<<price2<<"元"<<endl; 
}
int main()
{
	int r;
	cout<<"泳池半径为:";
	cin>>r;	 
	TPool R(r);
	R.fence();
	R.pass(); 
 } 
