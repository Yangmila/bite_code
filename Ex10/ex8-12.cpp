#include <iostream.h>
class A
{
public:
    A() {} 
    virtual void f() { cout<<"A::f() called. "<<endl; }
};
class B:public A
{
public:
    B() { f(); }
    void g() { f(); }
};
class C:public B
{
public:
    C() {} 
    virtual void f() { cout<<"C::f() called. "<<endl; }
};
void main()
{
    C c;
    c.g();
}
