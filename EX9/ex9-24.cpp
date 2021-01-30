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
      file.write((char *)&i,sizeof(int));//д��0-14
    streampos pos=file.tellp();                
    cout<<"Current byte number: "<<pos<<endl;
    for(i=15;i<45;i++)
      file.write((char *)&i,sizeof(int));//д��15-44
    file.seekp(pos);//���ö�ָ�뵽60�ֽڴ�����15
    file.read((char *)&i,sizeof(int));
    cout<<"The data stored is "<<i<<endl;
    file.seekp(0,ios::beg);//����дָ�����Ŀ�ʼλ��
    for(i=80;i<100;i++)
      file.write((char *)&i,sizeof(int));//80-99
    file.seekp(pos);//���ö�ָ�뵽60�ֽڴ�����95
    file.read((char *)&i,sizeof(int));
    cout<<"The data stored is "<<i<<endl;
    file.seekp(20,ios::cur);//�ӵ�ǰλ�����Ų��20�ֽڼ����������
    file.read((char *)&i,sizeof(int));
    cout<<"The data stored is "<<i<<endl;
    cout<<"Current byte number: "<<file.tellg()<<endl;
}