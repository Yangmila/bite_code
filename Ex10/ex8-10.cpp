#include <iostream.h>
class A
{
public:
    virtual void act1() 
        { cout<<"A::act1() called. "<<endl; }
    void act2() { act1(); }
};
class B:public A
{
public:
    void act1() {cout<<"B::act1() called. "<<endl;}
};
void main()
{
    B b;
    b.act2();
}
