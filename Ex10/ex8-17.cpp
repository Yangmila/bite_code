#include <iostream.h>
class A
{
  public:
     virtual ~A() { cout<<"A::~A() called.\n";}
};
class B:public A
{
  public:
    B(int i) {buf=new char[i];}
     ~B()
    {    
      delete [] buf;
      cout<<"B::~B() called.\n";
    }  
  private:
    char *buf;
};
void fun(A *a)
{
    delete a;
}
void main()
{
    A *a=new B(15);
    fun(a);
}
