#include <iostream.h>
class A
{
    public:
      A()   {X=Y=0;}
      A(int i,int j)   { X=i;Y=j;}
      A(A &p)  { X=p.X;Y=p.Y;}
      //A& operator =(A &p);
      int getX()     { return X;}
      int getY()     { return Y;}
    private:
      int X,Y;
};
/*A& A::operator =(A &p)
{
    X=p.X;    Y=p.Y;
    cout<<"Assignment operator called.\n";
    return *this;
}  */

void main()
{
    A a(7,8);
    A b;
    b=a;
    cout<<b.getX()<<","<<b.getY()<<endl;
}
