#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
void main()
{
    fstream file("f6.dat",ios::in|ios::out|ios::binary);
    if(!file)
    {
      cout<<"f6.dat can't open.\n";
      abort();
    }
    for(int i=0;i<15;i++)
      file.write((char *)&i,sizeof(int));//写入0-14
    streampos pos=file.tellp();                
    cout<<"Current byte number: "<<pos<<endl;
    for(i=15;i<45;i++)
      file.write((char *)&i,sizeof(int));//写入15-44
    file.seekp(pos);//设置读指针到60字节处，即15
    file.read((char *)&i,sizeof(int));
    cout<<"The data stored is "<<i<<endl;
    file.seekp(0,ios::beg);//设置写指针流的开始位置
    for(i=80;i<100;i++)
      file.write((char *)&i,sizeof(int));//80-99
    file.seekp(pos);//设置读指针到60字节处，即95
    file.read((char *)&i,sizeof(int));
    cout<<"The data stored is "<<i<<endl;
    file.seekp(20,ios::cur);//从当前位置向后挪动20字节及五个整数项
    file.read((char *)&i,sizeof(int));
    cout<<"The data stored is "<<i<<endl;
    cout<<"Current byte number: "<<file.tellg()<<endl;
}