#include <iostream>   
#include<cstdio>
using namespace std;  
bool b[100][100]; //ͼ���ڽӾ��� 

bool check(int x[],int n, int k)
{
    
    for(int i=1;i<k;i++)
    {
        if(x[i]==x[k] )
            return false;
    }
    int tmp1,tmp2;
    tmp1=x[k-1],tmp2=x[k];
    if(b[tmp1][tmp2]) //if(b[k-1][k])����
    {
        if(k==n)
            return b[1][tmp2]; //k����nҪ��������

        return true;
    }
    else
        return false;
}


void hamilton(int x[],int n,int k)
{
    for(int i=1;i<=n;i++)
    {
        x[k]=i;
        if(check(x,n,k))
        {
            if(k==n)
            {
                for(int m=1;m<=n;m++) cout<<x[m]<<ends;
                cout<<endl;
                 
            }
            else
            {
                hamilton(x,n,k+1);
            }
        }
    }
}
void hamilton2(int x[],int n)
{
    x[2]=0;
    int k=2;
    while(k>1)
    {
        x[k]+=1;
        while(x[k]<=n && !check(x,n,k) )
        {
            x[k]+=1;
        }
        if(x[k]<=n)
        {
            if(k==n)
            {
                for(int m=1;m<=n;m++) cout<<x[m]<<ends;
                cout<<endl;
                x[k]=0;
                k--;
            }
            else
            {
                k++;
                x[k]=0;
            }
        }
        else
        {
            x[k]=0;
            k--;
        }
    }
}
 
int main()
{
    freopen("hamilton.txt","r",stdin);
    int n;
    cout<<"���붥����"<<endl;
    cin>>n;

    int *x=new int[n+1];

    int edges;
    cout<<"����"<<endl;
    cin>>edges;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            {
                if(i==j) b[i][j]=true;
                else b[i][j]=false;
        }

    int start,end;
    cout<<"���ڱ�d�������յ�"<<endl;
    for(int i=1;i<=edges;i++)
    {
        cin>>start>>end;

        b[start][end]=true;
        b[end][start]=true;
    }
    x[1]=1;
    //hamilton(x,n,2);
    hamilton2(x,n);
}
