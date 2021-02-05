#include <iostream.h>
#include <string.h>
template <class stype> 
void bubble (stype *item, int count);
void main()
{
  char str[]="HUTREADHGKLP";
  bubble (str, (int)strlen (str));
  cout<<"The sorted string is:"<<str<<endl;

  int nums1[]={ 4, 7, 2, 9, 3, 7, 6, 1 };
  bubble (nums1, 8);
  cout<<"The sorted numbers are:";
  for (int i(0); i<8; i++)
    cout<<nums1[i]<<" ";
  cout<<endl;

  double nums2[]={ 2.3, 5.3, 6.7, 3.9, 7.2, 1.5 };
  bubble (nums2, 6);
  cout<<"The sorted numbers are:";
  for (i=0; i <6;i++)
    cout<<nums2[i]<<" ";
  cout<<endl;

}
template <class stype>
void bubble (stype *item, int count)
{
  register i, j;
  stype t;
  for (i=1; i<count; i++)
    for(j=count-1; j>=i; j--)
      if(item[j-1]>item[j])
      {
        t=item[j-1];
        item[j-1]=item[j];
        item[j]=t;
      }
}
