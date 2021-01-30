  #include <iostream.h>
  class Date
 {
   public:
       Date(int y,int m,int d)
       {        Year=y;        Month=m;        Day=d;    }
       friend ostream& operator <<
             (ostream& stream,Date& date);
       friend istream& operator >>   
             (istream& stream,Date& date);
   private:
       int Year,Month,Day;
  };
ostream& operator <<(ostream& stream,Date& date)
{
    stream<<date.Year<<"/"<<date.Month<<"/"
               <<date.Day<<endl;
    return stream;
}
istream& operator >>(istream& stream,Date& date)
{
    stream>>date.Year>>date.Month>>date.Day;
    return stream;
}
void main()
{
    Date CDate(1999,10,22);
    cout<<"Current date(yyyy/mm/dd): "<<CDate<<endl;
    cout<<"Enter new date(yyyy mm dd): ";
    cin>>CDate;
    cout<<"New date: "<<CDate<<endl;
}


