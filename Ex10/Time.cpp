#include <iostream.h>
class Time
{          
  private:
     int Hour,Minute,Second;
  public:
    Time(int H=0,int M=0,int S=0);
    void ShowTime12();
	void ShowTime24();
};
Time::Time(int H,int M,int S)
{if(H>=0&&H<24&&M>=0&&M<60&&S>=0&&S,60)
    { Hour=H;Minute=M;Second=S; }
 else
     cout<<" ʱ�����"<<endl;
}
void Time::ShowTime12()
{cout<<"12Сʱ��ʽ"<<Hour%12<<":"<<Minute<<":"<<Second<<endl;}
void Time::ShowTime24()
{cout<<"24Сʱ��ʽ"<<Hour<<":"<<Minute<<":"<<Second<<endl;}
void main()
{
   Time time(23,59,59);  	
   time.ShowTime12();
   time.ShowTime24(); 
}
