#include <iostream.h>
class complex
{
  public:
    complex()
    {real=imag=0.0;}
    complex(double a,double b)
    { real=a;imag=b;}
    friend complex operator +(const complex &c1,const complex &c2);
    friend ostream& operator <<(ostream &stre,const complex &c);
    friend istream& operator >>(istream &stre,complex &c);
  private:
    double real,imag;
};
complex operator +(const complex &c1,const complex &c2)
{
    double r=c1.real+c2.real;
    double i=c1.imag+c2.imag;
    return complex(r,i);
}
ostream& operator <<(ostream& stre,const complex &c)
{
    stre<<"("<<c.real<<","<<c.imag<<")";
    return stre;
}
istream& operator >>(istream& stre,complex &c)
{
    stre>>c.real>>c.imag;
    return stre;
}

void main()
{
    complex x,y,z;
    cout<<"Input two complex number:\n";
    cin>>x>>y;
    z=x+y;
    cout<<z<<endl;
}