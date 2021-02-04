#include <iostream.h>
#include <stdlib.h>
class Franc
{  
	public:
		Franc(){}
		Franc(int nu,int de)
		{   
			if(de==0)
            {   cerr<<"����Ϊ�㣡"<<endl;  exit(1); } 
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
   f.nume=f1.nume*f2.deno+f2.nume*f1.deno;  //�����������ķ���
   f.deno=f1.deno*f2.deno; //�����������ķ�ĸ
   f.FranSimp();    //�Խ�����м򻯴���
   return f;             //���ؽ������
}
Franc operator-(Franc f1,Franc f2)
{
   Franc f;
   f.nume=f1.nume*f2.deno-f2.nume*f1.deno;  //�����������ķ���
   f.deno=f1.deno*f2.deno; //�����������ķ�ĸ
   f.FranSimp();    //�Խ�����м򻯴���
   return f;             //���ؽ������
}Franc operator*(Franc f1,Franc f2)
{
   Franc f;
   f.nume=f1.nume*f2.nume;  //�����������ķ���
   f.deno=f1.deno*f2.deno; //�����������ķ�ĸ
   f.FranSimp();    //�Խ�����м򻯴���
   return f;             //���ؽ������
}
Franc operator/(Franc f1,Franc f2)
{
   Franc f;
   f.nume=f1.nume*f2.deno;  //�����������ķ���
   f.deno=f1.deno*f2.nume; //�����������ķ�ĸ
   f.FranSimp();    //�Խ�����м򻯴���
   return f;             //���ؽ������
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
{    Franc f1(5,6),f2(1,-2),f3;   	//������������     
     cout<<"f1=";f1.display();  
     cout<<"f2=";f2.display();
     f3=f1+f2;         //�����������ʵ�ַ����ӷ�        
     cout<<"f1+f2=";f3.display();
	      f3=f1-f2;         //�����������ʵ�ַ����ӷ�        
     cout<<"f1-f2=";f3.display();
	      f3=f1*f2;         //�����������ʵ�ַ����ӷ�        
     cout<<"f1*f2=";f3.display();
	      f3=f1/f2+f3;         //�����������ʵ�ַ����ӷ�        
     cout<<"f1/f2=";f3.display();
     if(f1==f2) cout<<"f1��f2���"<<endl;  //�ж�f1��f2�Ƿ���
       else cout<<"f1��f2�����"<<endl;
	 if(f1>f2) cout<<"f1>f2"<<endl;  //�ж�f1��f2�Ƿ���
       else cout<<"f1<=f2"<<endl;
}
