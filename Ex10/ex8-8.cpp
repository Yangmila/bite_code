// ch 8.8.cpp, ����ʱ�Ķ�̬��
#include<iostream.h>
class shap //��Point�Ķ���
{	
    public:
		shap(  )		{     }
		virtual double area()=0;
		
  
};
class Point public:shap //��Point�Ķ���
{	
    public:
		Point( double i=0, double j=0 )
		{   x=i,  y=j;   }
		virtual double area() 	//���ص����� (0.0)
		{  cout<<"��������"; return 0.0;  }
    protected:
		double x,y; 	//�������
};
const double pi=3.14159;
class Circle : public Point //��Circle�Ķ���
{
	public:
		Circle( double i=0, double j=0, double r=1 ) : Point( i,j )
		{   radius=r;   }
		Circle(Circle  &t):Point(t.x,t.y) //���ƹ��캯��
		{  radius=t.radius;   }
		double area() 	//����Բ�����
		{  cout<<"Բ�������";	 return pi*radius*radius;   }
		double getRadius()
		{   return radius;  }
	protected:
		double radius;
};
class Arc: public Circle  //�໡�Ķ���
{
	public:	      //�������к�����Ա
		Arc(double x, double y, double r, double a1,double a2) 
			: Circle(x,y,r)
		{   startAngle=a1;endAngle=a2;   }	//�����๹�캯��
		double area()
		{
			cout<<"���������";
			return  pi*radius*radius*(endAngle-startAngle)/180;
		}
	private:		//����˽�����ݳ�Ա
		double startAngle,endAngle;
};
void main()
{
	Point p(2,3); 		//����Point ������ָ�� 
	cout<<p.area()<<endl;  //?
	Circle c1( 1, 1, 10 ),c2(2,3,20); 	//��������Circle �����
	cout<<"�뾶Ϊ "<<c1.getRadius()<<",���Ϊ"<<c1.area()<<endl;  //?
	Circle c (c2); 	
    //����Circle��Ķ��󣬵���Circle��ĸ��ƹ��캯��
    cout<<"�뾶Ϊ: "<<c.getRadius()<<" ,���Ϊ"<<c.area()<<endl;
    Arc a (2,3,20,10,20); 	//����Arc �����  //?
    cout<<a.area()<<endl; 	//����������
	Point *pptr=&p; //����Point ��ָ��pptrָ��Point�����p
	cout<<pptr->area()<<endl;  //?
	pptr=&c;  //����ָ��ָ��Clircle��Ķ���
	cout<<pptr->area()<<endl;  //?
	pptr=&a;    //����ָ��ָ��Arc��Ķ���
	cout<<pptr->area()<<endl;  //?
}
