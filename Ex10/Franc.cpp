#include <iostream.h>
#include <stdlib.h>
class Franc
{  
	public:
		Franc(){}
		Franc(int nu,int de)
		{   
			if(de==0)
            {   cerr<<"除数为零！"<<endl;  exit(1); } 
			nume=nu;deno=de;
        }
		friend Franc operator+(Franc f1,Franc f2);
		friend Franc operator-(Franc f1,Franc f2);
		friend Franc operator*(Franc f1,Franc f2);
		friend Franc operator/(Franc f1,Franc f2);
		friend bool operator==(Franc f1,Franc f2);
		friend bool operator>(Franc f1,Franc f2);
		void FranSimp();
		void display() 
		{  cout<<nume<<"/"<<deno<<endl; }
	private:
		int nume;  int deno;
};
Franc operator+(Franc f1,Franc f2)
{
   Franc f;
   f.nume=f1.nume*f2.deno+f2.nume*f1.deno;  //计算结果分数的分子
   f.deno=f1.deno*f2.deno; //计算结果分数的分母
   f.FranSimp();    //对结果进行简化处理
   return f;             //返回结果分数
}
Franc operator-(Franc f1,Franc f2)
{
   Franc f;
   f.nume=f1.nume*f2.deno-f2.nume*f1.deno;  //计算结果分数的分子
   f.deno=f1.deno*f2.deno; //计算结果分数的分母
   f.FranSimp();    //对结果进行简化处理
   return f;             //返回结果分数
}Franc operator*(Franc f1,Franc f2)
{
   Franc f;
   f.nume=f1.nume*f2.nume;  //计算结果分数的分子
   f.deno=f1.deno*f2.deno; //计算结果分数的分母
   f.FranSimp();    //对结果进行简化处理
   return f;             //返回结果分数
}
Franc operator/(Franc f1,Franc f2)
{
   Franc f;
   f.nume=f1.nume*f2.deno;  //计算结果分数的分子
   f.deno=f1.deno*f2.nume; //计算结果分数的分母
   f.FranSimp();    //对结果进行简化处理
   return f;             //返回结果分数
}
bool  operator==(Franc f1,Franc f2)
{
   if(f1.nume*f2.deno==f2.nume*f1.deno)
   return true;
   else
   return false;
}
bool  operator>(Franc f1,Franc f2)
{
   if(f1.nume*f2.deno>f2.nume*f1.deno)
   return true;
   else
   return false;
}
void Franc::FranSimp()
{
	int n,d,t;
	n=nume;d=deno;
	if(n<d){ t=n,n=d,d=t;}
	while(d)
	{ t=n%d;n=d;d=t;}
	nume=nume/n;deno=deno/n;
}
void main()
{    Franc f1(5,6),f2(1,-2),f3;   	//定义分数类对象     
     cout<<"f1=";f1.display();  
     cout<<"f2=";f2.display();
     f3=f1+f2;         //用重载运算符实现分数加法        
     cout<<"f1+f2=";f3.display();
	      f3=f1-f2;         //用重载运算符实现分数加法        
     cout<<"f1-f2=";f3.display();
	      f3=f1*f2;         //用重载运算符实现分数加法        
     cout<<"f1*f2=";f3.display();
	      f3=f1/f2+f3;         //用重载运算符实现分数加法        
     cout<<"f1/f2=";f3.display();
     if(f1==f2) cout<<"f1和f2相等"<<endl;  //判断f1和f2是否相
       else cout<<"f1和f2不相等"<<endl;
	 if(f1>f2) cout<<"f1>f2"<<endl;  //判断f1和f2是否相
       else cout<<"f1<=f2"<<endl;
}
