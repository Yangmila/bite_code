#include <iostream>
#include <math.h>
using namespace std;
class Point	//Point������
{ public:	//�ⲿ�ӿ�
	   Point(int xx=0, int yy=0) {X=xx;Y=yy;}
	   int GetX()const {return X;}
	   int GetY()const {return Y;}
  private:	//˽�����ݳ�Ա
	   int X,Y;  
  };

double Distance(const Point& a, const Point& b)
{
      double dx=a.GetX()-b.GetX();
      double dy=a.GetY()-b.GetY();
      return sqrt(dx*dx+dy*dy);
}
const int M=10;
int main()
{  
	const Point p1(3.0, 5.0), p2(4.0, 6.0);
	Point p3(4.0, 5.0);

    double d=Distance(p1, p2);
    cout<<"The distance is "<<d<<endl;
	cout<<p3.GetX()<<endl;
}

