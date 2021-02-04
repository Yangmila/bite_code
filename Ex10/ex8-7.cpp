#include <iostream.h>
class F
{
public:
    double operator () (double x,double y) const;
};
double F::operator () (double x,double y) const
{
    return x*y+5;
}
void main()
{
    F f;
    cout<<f(5.2,2.5)<<endl;
}
