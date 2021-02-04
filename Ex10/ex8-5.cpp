#include <iostream.h>
/*class CharArray
{
    public:
      CharArray(int l)
      {  
          Length=l;
          Buff=new char[Length];
      }  
      ~CharArray()
      { delete Buff;}
      int GetLength()
      { return Length;}
     // char & operator [](int i);
    private:
      int Length;
      char *Buff;
};
char & CharArray::operator [](int i)
{
    static char ch=0;
    if(i<Length&&i>=0)
      return Buff[i];
    else
    {
      cout<<"\nIndex out of range.";
      return ch;
    }
}*/
void main()
{
    int cnt;
    char string1[6];
    char *string2="string";
    for(cnt=0;cnt<8;cnt++)
       *(string1+cnt)=*(string2+cnt);
    cout<<"\n";
    for(cnt=0;cnt<8;cnt++)
       cout<<*(string1+cnt);
    cout<<"\n";
    //cout<<string1.GetLength()<<endl;
}