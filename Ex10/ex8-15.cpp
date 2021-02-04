#include <iostream.h>
class Point
{
	public:
		Point(int i=0,int j=0) {x0=i;y0=j;}
		virtual void Set()=0;
		virtual void Draw()=0;
	protected:
		int x0,y0;
};
class Line:public Point
{
	public:    
		Line(int i=0,int j=0,int m=0,int n=0):Point(i,j)
        {x1=m;y1=n;}
    void Set() 
	{cout<<"Line::Set() called. "<<endl;}
    void Draw() 
	{cout<<"Line::Draw() called. "<<endl;}
	protected:
		int x1,y1;
};
class Ellipse:public Point
{
	public:
		Ellipse(int i=0,int j=0,int p=0,int q=0):Point(i,j)
        {x2=p;y2=q;}
		void Set() 
		{cout<<"Ellipse::Set() called. "<<endl;}
		void Draw()
        {cout<<"Ellipse::Draw() called. "<<endl;}
	protected:
		int x2,y2;
};
void DrawObj(Point* p)
{    p->Draw();  }
void SetObj(Point* p)
{    p->Set();  }
void main()
{
    Line *lineobj=new Line;
    Ellipse *ellipseobj=new Ellipse;
    DrawObj(lineobj);
    DrawObj(ellipseobj);
    cout<<endl;
    SetObj(lineobj);
    SetObj(ellipseobj);
    cout<<endl<<"Redraw the object¡­"<<endl;
    DrawObj(lineobj);
    DrawObj(ellipseobj);
}
