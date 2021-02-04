class integer
{
public:
    integer(int i=0) {value=i;}
    friend integer operator +(integer i1,integer i2);
private:
    int value;
};
integer operator +(integer i1,integer i2)
{
    integer temp=i1.value+i2.value;
    return temp;
}
void main()
{
    integer i1=10;
    integer i2=i1+5;
    integer i3=3+i2;
}