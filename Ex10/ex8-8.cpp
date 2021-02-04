// ch 8.8.cpp, 编译时的多态性
#include<iostream.h>
class shap //类Point的定义
{	
    public:
		shap(  )		{     }
		virtual double area()=0;
		
  
};
class Point public:shap //类Point的定义
{	
    public:
		Point( double i=0, double j=0 )
		{   x=i,  y=j;   }
		virtual double area() 	//返回点的面积 (0.0)
		{  cout<<"点的面积："; return 0.0;  }
    protected:
		double x,y; 	//点的坐标
};
const double pi=3.14159;
class Circle : public Point //类Circle的定义
{
	public:
		Circle( double i=0, double j=0, double r=1 ) : Point( i,j )
		{   radius=r;   }
		Circle(Circle  &t):Point(t.x,t.y) //复制构造函数
		{  radius=t.radius;   }
		double area() 	//返回圆的面积
		{  cout<<"圆的面积：";	 return pi*radius*radius;   }
		double getRadius()
		{   return radius;  }
	protected:
		double radius;
};
class Arc: public Circle  //类弧的定义
{
	public:	      //新增公有函数成员
		Arc(double x, double y, double r, double a1,double a2) 
			: Circle(x,y,r)
		{   startAngle=a1;endAngle=a2;   }	//派生类构造函数
		double area()
		{
			cout<<"弧的面积：";
			return  pi*radius*radius*(endAngle-startAngle)/180;
		}
	private:		//新增私有数据成员
		double startAngle,endAngle;
};
void main()
{
	Point p(2,3); 		//声明Point 类对象和指针 
	cout<<p.area()<<endl;  //?
	Circle c1( 1, 1, 10 ),c2(2,3,20); 	//声明两个Circle 类对象
	cout<<"半径为 "<<c1.getRadius()<<",面积为"<<c1.area()<<endl;  //?
	Circle c (c2); 	
    //声明Circle类的对象，调用Circle类的复制构造函数
    cout<<"半径为: "<<c.getRadius()<<" ,面积为"<<c.area()<<endl;
    Arc a (2,3,20,10,20); 	//声明Arc 类对象  //?
    cout<<a.area()<<endl; 	//输出弧的面积
	Point *pptr=&p; //声明Point 类指针pptr指向Point类对象p
	cout<<pptr->area()<<endl;  //?
	pptr=&c;  //基类指针指向Clircle类的对象
	cout<<pptr->area()<<endl;  //?
	pptr=&a;    //基类指针指向Arc类的对象
	cout<<pptr->area()<<endl;  //?
}
