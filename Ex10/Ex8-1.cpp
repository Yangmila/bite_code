#include <iostream.h>
#include <string.h>
class string
{
public:
    string(char *s);
    string(string &s1);
    string(int size=80);
    ~string() {delete sptr;}
    int GetLen() {return length;}
    void Print() {cout<<sptr<<endl;}
private:
    char *sptr;
    int length;
};
string::string(char *s)
{
    length=strlen(s);
    sptr=new char[length+1];
    strcpy(sptr,s);
}
string::string(string &s1)
{
    length=s1.length;
    sptr=new char[length+1];
    strcpy(sptr,s1.sptr);
}
string::string(int size)
{
    length=size;
    sptr=new char[length+1];
    *sptr='\0';
}
void main()
{
    string str1("This is a string.");
    str1.Print();
    cout<<str1.GetLen()<<endl;
    char *s1="That is a program.";
    string str2(s1);
    string str3(str2);
    str3.Print();
    cout<<str3.GetLen()<<endl;
}
