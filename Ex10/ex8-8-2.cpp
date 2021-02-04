#include<iostream.h>
class Point //��Point�Ķ���
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
   Point p;                    //����Point ������ָ��
   Circle c1(1,1,10);    //��������Circle �����
   Arc a1(1,1,10,10,20);       //����Arc �����
   Point *pptr[3];                 //��������ָ������
   pptr[0]=&p ;           //ָ��Point�����p
   pptr[1]=&c1;          //����ָ��ָ��Clircle��Ķ���
   pptr[2]=&a1;         //����ָ��ָ��Arc��Ķ���
// �����ָ��ָ��������Ķ���, ���Ի������ʱ�Ķ�̬��
   cout << "ͨ�������ָ��ʵ�ֶ�̬��̬:\n";     
   for ( int i = 0; i < 3; i++ ) 
     cout<<pptr[i]->area()<<endl;  //?
// ��������Ķ��󸳸���������, p.area() ��Ȼ���û����ж�����麯��
   cout<<"���������ֵ�o�������(��̬��̬):"<<endl; 
    p=c1;  
    cout<<p.area()<<endl;  //?
   // ���������,����������Ķ���, Ҳ���Ի������ʱ�Ķ�̬��
   cout << "ͨ�����������ʵ�ֶ�̬��̬:\n";         
   Circle c2( 2, 2, 20 ); 
   Point &pRef=c2;  
   cout<<pRef.area()<<endl;  //?
}
