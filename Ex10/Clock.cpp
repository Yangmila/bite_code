#include <iostream.h>
class Clock{          //定义时钟类
  private:
     int Hour,Minute,Second;
  public:
    Clock(int H=0,int M=0,int S=0);
    void ShowTime();
    void   operator++(); //前置单目运算符重载成员函数
    Clock  operator++(int); 	//后置单目运算符重载成员函数
 };
Clock::Clock(int H,int M,int S)
{if(H>=0&&H<24&&M>=0&&M<60&&S>=0&&S,60)
    { Hour=H;Minute=M;Second=S; }
 else
     cout<<" 时间错误！"<<endl;
}
void Clock::ShowTime()
{cout<<Hour<<":"<<Minute<<":"<<Second<<endl;}
void Clock::operator++()
{   Second++;
   if(Second>=60)
   { Second-=60;     Minute++;
     if(Minute>=60)
	 { Minute-=60;Hour++;Hour%=24; }
   }
}
Clock Clock:: operator++(int)
{
    Clock h;
    Second++;
    if(Second>=60)
   { Second-=60;
     Minute++;
     if(Minute>=60)
	{ Minute-=60;Hour++;Hour%=24; }
   }
   return h;
}
void main()
{
   Clock clock(23,59,59),c;  		//定义时钟对象
   cout<<"First time:";clock.ShowTime();
   ++clock;  
   cout<<"++clock:";clock.ShowTime(); 
   c=clock++;
   cout<<"clock++:";c.ShowTime();
   cout<<"colck:";clock.ShowTime();
  }
