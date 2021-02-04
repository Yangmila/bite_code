 #include  <iostream.h>
  class complex                                             //定义复数类；
  {
  public:
	complex(double r=0.0,double i=0.0)           //构造函数；
	{
		real=r;
		imag=i;
	}     //运算符"+" "-" "*" "/"重载为友元函数；
	friend complex operator +(const complex &c1,const complex &c2); 
	friend complex operator -(const complex &c1,const complex &c2);  
	friend complex operator *(const complex &c1,const complex &c2);  
	friend complex operator /(const complex &c1,const complex &c2);  
	void print()
	{
	   if(imag<0)                                      
		     cout<<real<<imag<<"i"<<endl;           //复数虚部小于0时；
	   else                                                 
		     cout<<real<<"+"<<imag<<"i"<<endl;      //复数虚部大于0时；
	} 
  private:
	double real,imag;
  };
complex operator+(const complex &c1,const complex &c2)   //重载"+"的定义；
{
	  return complex(c1.real+c2.real,c1.imag+c2.imag);
}
complex operator-(const complex &c1,const complex &c2)   //重载"-"的定义；
{
	  return complex(c1.real-c2.real,c1.imag-c2.imag);
}
complex operator*(const complex &c1,const complex &c2)   //重载"*"的定义；
{
	  return complex(c1.real*c2.real-c1.imag*c2.imag,c1.real*c2.imag+
                                                    c1.imag*c2.real);
}
complex operator/(const complex &c1,const complex &c2)   //重载"/"的定义；
{
	  return complex(
  (c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag),
		  (c1.imag*c2.real+c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag));
}
void main()
{
	  complex s1(1.6,3.8),s2(5.7,2.3),s3,s4,s5,s6,s7;
	  s3=s1+s2;        
	  //隐式调用operator+()，可解释为operator+(s1,s2)（显示调用）；
	  cout<<"s3=s1+s2=";
	  s3.print();    
	  s4=s1-s2;        
	  //隐式调用operator-()，可解释为operator-(s1,s2)（显示调用）；
	  cout<<"s4=s1-s2=";
	  s4.print();
	  s5=s1*s2;       
	  //隐式调用operator*()，可解释为operator*(s1,s2)（显示调用）;
	  cout<<"s5=s1*s2=";
	  s5.print();
	  s6=s1/s2;       
	  //隐式调用operator/()，可解释为operator/(s1,s2)（显示调用）；
	  cout<<"s6=s1/s2=";
	  s6.print();
	  s7=(s1+s3)*s2-(s4-s5)/s6;              
	  //重载运算符的混合运算；
	  cout<<"s7=(s1+s3)*s2-(s4-s5)/s6=";
	  s7.print();
}
