#include <iostream>
using namespace std;
template <class T>
class Tpoint
{

	public:
		//系统接口
		Tpoint(T xx=0,T yy=0);
		//用户接口
		void Set_point(T xx=0,T yy=0);
		void Mov_point( T xx=0,T yy=0);
		void Print();
		T Get_x(){return x;}
		T Get_y(){return y;}		
	private:
		T x,y;
};

template <class T>
Tpoint<T>::Tpoint(T xx,T yy)
{
	x=xx;y=yy;
}
template <class T>
void Tpoint<T>::Set_point(T xx,T yy)
{
	x=xx;y=yy;
}
template <class T>
void Tpoint<T>::Mov_point(T xx,T yy)
{
	x=x+xx;y=y+yy;
}
template <class T>
void Tpoint<T>::Print()
{
	cout<<"("<<x<<","<<y<<")"<<endl;
}