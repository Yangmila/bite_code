#include <iostream.h>
int &fun(char, int &, int &);
void main()
{
  int tn(0), tc(0);
  cout<<"Enter characters:";
  char ch;
  cin>>ch;
  while(ch!='#')
  {    fun(ch, tn, tc)++;    cin>>ch;  }
  cout<<"Number characters: "<<tn<<endl;
  cout<<"Other characters: "<<tc<<endl;
}
int & fun(char cha, int & n, int & c)
{
  if(cha>='0'&& cha<='9')
    return n;
  else
    return c;
}
