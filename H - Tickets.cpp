#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
const long long mod = 1e9+7;
typedef long long int ll;
#define maxn 10000+5
#define INF 0x3f3f3f3f
#define LLF 0x7fffffffffffffff
int a[maxn],b[maxn];
int dp[maxn];
int main(){

    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        int k,h=8,m=0,s=0;
        scanf("%d",&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&a[i]);
        }
        for(int i=2;i<=k;i++){
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=k;i++){
            if(i>=2)
            dp[i]=min(dp[i-1]+a[i],dp[i-2]+b[i]);
            else dp[i]=dp[i-1]+a[i];
        }
        s+=dp[k];
        int flag=0;
        m+=s/60;s%=60;h+=m/60;m%=60;
        if(h>12)h-=12,flag++;
        printf("%02d:%02d:%02d ",h,m,s);
        if(!flag)printf("am\n");
        else printf("pm\n");
    }
}
