#include <iostream.h>
class counter
{
public:
    counter() {value=0;}
    counter operator ++();
    counter operator ++(int);
    void display() {cout<<value<<endl;}
private:
    int value;
};
counter counter::operator ++()
{
    value++;
    return *this;
}
counter counter::operator ++(int i)
{
    counter t;
    t.value=value++;
    return t;
}
void main()
{
    counter c;
    c.display();
    for(int i=0;i<10;i++)
        c++;
    c.display();
    for(i=0;i<10;i++)
        ++c;
    c.display();
}
