/*
*copyright@nciaebupt ת����ע������
*���⣺�������������������
*дһ��ʱ�临�ӶȾ����ܵ͵ĳ�����һ��һά���飨N��Ԫ�أ��е�����������еĳ��ȡ�
*���磺������1��-1,2��-3,4��-5,6��-7�У�����ĵ���������Ϊ1,2,4,6,�����������
*�ĳ���Ϊ4��
*���˼·��ʹ�ö�̬�滮�㷨 ʱ�临�Ӷ�O(n^2)
*/
#include <cstdio>
#include <iostream>
 
using namespace std;
 
int MAX(int *LIS,int len)
{
    int max = 0;
    for(int i = 0;i < len;++i)
    {
        cout<<i<<"  "<<LIS[i]<<endl;
        if(LIS[i] > max)
            max = LIS[i];
    }
    return max;
}
 
int LIS(int *array,int len)
{
    int *LIS = new int[len];//���ڼ�¼��ǰ��Ԫ����Ϊ���Ԫ�ص���������г���
    for(int i = 0;i < len;++i)
    {
        LIS[i] = 1;//���õ�ǰԪ��array[i]��Ϊ���Ԫ�ص���������г���Ϊ1
        for(int j = 0; j < i;++j)
        {
            if(array[i] > array[j] && LIS[j] + 1 > LIS[i])
            {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    int res = MAX(LIS,len);
    delete LIS;
    return res;//���LIS�е����ֵ�����أ�
}
 
int main(int args,char ** argv)
{
    int array[] = {1,-1,2,-3,4,-5,6,-7};
    int len = sizeof(array)/sizeof(int);
    int res = LIS(array,len);
    cout<<res<<endl;
    getchar();
    return 0;
}
