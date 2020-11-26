#include <iostream>

#define N 205

using namespace std;

 

int c[N][N];

int x[N];

int BestM[N];

int n;

int Bmin=999999999;

 

int sum(int k)

{
    int temp=0;

    for(int i=1;i<=k;i++)

        temp+=c[i][x[i]];

    return temp;

}

 

void backtrack(int t)

{
    if (t==n){
        int ans=sum(n);

        if(ans<Bmin){
            Bmin=ans;

            for(int i=1;i<=n;i++)

            BestM[i]=x[i];

        }

    }

    else

      for (int i=t;i<=n;i++) {
        swap(x[t], x[i]);

        if(sum(t)<Bmin)

        backtrack(t+1);

        swap(x[t], x[i]);

      }

}

 

int main()

{
    cin>>n;

    for(int i=1;i<=n;i++)

      for(int j=1;j<=n;j++)

        cin>>c[i][j];

    for(int i=1;i<=n;i++)

        x[i]=i;

    backtrack(1);

    for(int i=1;i<=n;i++)

    cout<<BestM[i]<<" ";

    return 0;

}
