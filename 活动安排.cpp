#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct nnn
{
int f;int a;int b;
}s[1005];
int comp(nnn x,nnn y)
{
return x.b<y.b;
}
int n,m=-1,ml,ans,an[1000];
bool f[10000];
int main()
{
int k=0;
scanf("%d",&n);
for(int i=1;i<=n;i++)
{
scanf("%d%d",&s[i].a,&s[i].b);
s[i].f=i;
}
sort(s+1,s+n+1,comp);
for(int i=1;i<n;i++)
for(int j=i+1;j<=n;j++)
if(s[i].a>s[j].a)
{
for(int k=j;k<=n;k++)
s[k]=s[k+1];
n--;
}
for(int i=1;i<=n;i++)
{
f[0]=0;
for(int j=s[i].a;j<s[i].b;j++)
if(f[j])
f[0]=1;
if(!f[0])
{
an[++ml]=s[i].f;
for(int j=s[i].a;j<s[i].b;j++)
f[j]=1;
m=max(m,s[i].b);
k++;
}

}
sort(an+1,an+ml+1);
printf("%d\n",k);
}

