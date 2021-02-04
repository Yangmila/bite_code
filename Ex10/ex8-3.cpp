 #include  <iostream.h>
  class complex                                             //���帴���ࣻ
  {
  public:
	complex(double r=0.0,double i=0.0)           //���캯����
	{
		real=r;
		imag=i;
	}     //�����"+" "-" "*" "/"����Ϊ��Ԫ������
	friend complex operator +(const complex &c1,const complex &c2); 
	friend complex operator -(const complex &c1,const complex &c2);  
	friend complex operator *(const complex &c1,const complex &c2);  
	friend complex operator /(const complex &c1,const complex &c2);  
	void print()
	{
	   if(imag<0)                                      
		     cout<<real<<imag<<"i"<<endl;           //�����鲿С��0ʱ��
	   else                                                 
		     cout<<real<<"+"<<imag<<"i"<<endl;      //�����鲿����0ʱ��
	} 
  private:
	double real,imag;
  };
complex operator+(const complex &c1,const complex &c2)   //����"+"�Ķ��壻
{
	  return complex(c1.real+c2.real,c1.imag+c2.imag);
}
complex operator-(const complex &c1,const complex &c2)   //����"-"�Ķ��壻
{
	  return complex(c1.real-c2.real,c1.imag-c2.imag);
}
complex operator*(const complex &c1,const complex &c2)   //����"*"�Ķ��壻
{
	  return complex(c1.real*c2.real-c1.imag*c2.imag,c1.real*c2.imag+
                                                    c1.imag*c2.real);
}
complex operator/(const complex &c1,const complex &c2)   //����"/"�Ķ��壻
{
	  return complex(
  (c1.real*c2.real+c1.imag*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag),
		  (c1.imag*c2.real+c1.real*c2.imag)/(c2.real*c2.real+c2.imag*c2.imag));
}
void main()
{
	  complex s1(1.6,3.8),s2(5.7,2.3),s3,s4,s5,s6,s7;
	  s3=s1+s2;        
	  //��ʽ����operator+()���ɽ���Ϊoperator+(s1,s2)����ʾ���ã���
	  cout<<"s3=s1+s2=";
	  s3.print();    
	  s4=s1-s2;        
	  //��ʽ����operator-()���ɽ���Ϊoperator-(s1,s2)����ʾ���ã���
	  cout<<"s4=s1-s2=";
	  s4.print();
	  s5=s1*s2;       
	  //��ʽ����operator*()���ɽ���Ϊoperator*(s1,s2)����ʾ���ã�;
	  cout<<"s5=s1*s2=";
	  s5.print();
	  s6=s1/s2;       
	  //��ʽ����operator/()���ɽ���Ϊoperator/(s1,s2)����ʾ���ã���
	  cout<<"s6=s1/s2=";
	  s6.print();
	  s7=(s1+s3)*s2-(s4-s5)/s6;              
	  //����������Ļ�����㣻
	  cout<<"s7=(s1+s3)*s2-(s4-s5)/s6=";
	  s7.print();
}
