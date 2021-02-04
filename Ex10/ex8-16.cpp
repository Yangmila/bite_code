#include <iostream.h>
#include <math.h>
class F
{
  public:
    virtual double operator()(double x) const=0;
};
class Function:public F
{
  public:
    double operator()(double x) const
    {  
      return log(1.0+x)/(1.0+x*x);
    }  
};
class Integral
{
  public:
    virtual double operator()(double a,double b,double eps) const=0;
};
class Simpson: public Integral
{
  public:
    Simpson(const F &ff):f(ff)
    {  }          
    virtual double operator()(double a,double b,double eps) const;
  private:
    const F &f;
};
double Simpson::operator()(double a,double b,double eps) const
{
    int done(0);
    int n;
    double h,Tn,T2n,In,I2n;
    n=1;
    h=b-a;
    Tn=h*(f(a)-f(b))/2.0;
    In=Tn;
    while(!done)
    {
      double temp(0.0);
      for(int k=0;k<=n-1;k++)
      {  
        double x=a+(k+0.5)*h;
        temp+=f(x);
      }
      T2n=(Tn+h*temp)/2.0;
      I2n=(4.0*T2n-Tn)/3.0;
      if(fabs(I2n-In)<eps)
        done=1;
      else
      {  
        Tn=T2n;
        n*=2;
        h/=2;
        In=I2n;
      }  
    }
    return I2n;
}

void main()
{
    Function f;
    Simpson simp(f);
    cout<<simp(0,2,1E-7)<<endl;
}

