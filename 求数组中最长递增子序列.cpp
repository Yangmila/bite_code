/*
*copyright@nciaebupt 转载请注明出处
*问题：求数组中最长递增子序列
*写一个时间复杂度尽可能低的程序，求一个一维数组（N个元素）中的最长递增子序列的长度。
*例如：在序列1，-1,2，-3,4，-5,6，-7中，其最长的递增子序列为1,2,4,6,最长递增子序列
*的长度为4。
*求解思路：使用动态规划算法 时间复杂度O(n^2)
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
    int *LIS = new int[len];//用于记录当前各元素作为最大元素的最长递增序列长度
    for(int i = 0;i < len;++i)
    {
        LIS[i] = 1;//设置当前元素array[i]作为最大元素的最长递增序列长度为1
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
    return res;//获得LIS中的最大值并返回；
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
