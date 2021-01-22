class Point
{
public:
	//系统接口
	//Point(){}
	//Point(int x)
	//Point(int x,int y);
	Point(int x=0,int y=0);
	Point(const Point & p);

	~Point(){}
	//用户接口
	void SetPoint(int x=10,int y=20);
	int GetX(){return X;}
	int GetY(){return Y;}
	void OutPut();
	void OutPut(int );
private:
	char classname[20];
	int X,Y;
};
inline Point::Point(int x,int y)
{
	X=x,Y=y;
}
inline Point::Point(const Point & p)
{
	X=p.X,Y=p.Y;
}
inline void Point::SetPoint(int x,int y)
{
	X=x,Y=y;
}
inline void Point::OutPut()
{cout<<"("<<X<<","<<Y<<")"<<endl;}
inline void Point::OutPut(int )
{cout<<"<"<<X<<","<<Y<<">"<<endl;}
