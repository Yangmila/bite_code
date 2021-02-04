#include<iostream.h>
class Point //类Point的定义
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
   Point p;                    //声明Point 类对象和指针
   Circle c1(1,1,10);    //声明两个Circle 类对象
   Arc a1(1,1,10,10,20);       //声明Arc 类对象
   Point *pptr[3];                 //声明基类指针数组
   pptr[0]=&p ;           //指向Point类对象p
   pptr[1]=&c1;          //基类指针指向Clircle类的对象
   pptr[2]=&a1;         //基类指针指向Arc类的对象
// 基类的指针指向派生类的对象, 可以获得运行时的多态性
   cout << "通过基类的指针实现动态多态:\n";     
   for ( int i = 0; i < 3; i++ ) 
     cout<<pptr[i]->area()<<endl;  //?
// 将派生类的对象赋给基类对象后, p.area() 仍然调用基类中定义的虚函数
   cout<<"派生类对象赋值給基类对象(静态多态):"<<endl; 
    p=c1;  
    cout<<p.area()<<endl;  //?
   // 基类的引用,引用派生类的对象, 也可以获得运行时的多态性
   cout << "通过基类的引用实现动态多态:\n";         
   Circle c2( 2, 2, 20 ); 
   Point &pRef=c2;  
   cout<<pRef.area()<<endl;  //?
}
