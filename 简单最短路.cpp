#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 5;
#define INF 0x3f3f3f3f
#define mem(a) memset(a,0,sizeof a)
int Map[maxn][maxn];
int dis[maxn],check[maxn];
int n,m,a,b,c;

void init_map(int n,int m){
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      Map[i][j] = INF;
    }
  }
  for(int i=0;i<m;i++){
    cin>>a>>b>>c;
    if(Map[a][b]>c){
      Map[a][b] = Map[b][a] = c;
    }
  }
}

int dijkstra(int n,int m){
  mem(check);mem(dis);
  for(int i=1;i<=n;i++){
    dis[i]=Map[1][i];
  }
  check[1]=1,dis[0]=0;
  int minx=0,pos;
  for(int i=1;i<n;i++){       //���ҵ�ǰ����·�������δ���ʵĽ�㣬������ǰ������S
    minx = INF;
    for(int j=1;j<=n;j++){
      if(!check[j] && minx > dis[j]){
        minx = dis[j];
        pos = j;
      }
    }
    check[pos] = 1;             //������s����
    for(int j=1;j<=n;j++){      //����������δ����S��ֵ�����ͨ���н��㵽��ý��·���϶̣�����и���
      if(!check[j] && dis[j] > dis[pos] + Map[pos][j]){
        dis[j] = dis[pos] + Map[pos][j];
      }
    }
  }
  return dis[n];
}

int main(){
    cin>>n>>m;
    init_map(n,m);
    cout<<dijkstra(n,m)<<endl;
  return 0;
}

