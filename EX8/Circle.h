class Tcircle
{

	public:
		//系统接口
		Tcircle(int xx=0,int yy=0,float Ra=0);
		//用户接口
		//void Set_point(int xx=0,int yy=0);
		void Mov_point(int xx=0,int yy=0);
		void Print();
		//int Get_x(){return x;}
		//int Get_y(){return y;}		
	private:
		Tpoint Center;
		float Radius ;
};
Tcircle::Tcircle(int xx,int yy,float Ra)
:Center(xx,yy)
{
	Radius=Ra;
}
void Tcircle::Mov_point(int xx,int yy)
{
	Center.Mov_point(xx,yy);

}
void Tcircle::Print()
{
	cout<<"Center:";
	Center.Print();
	cout<<"Radius:"<<Radius<<endl;

}