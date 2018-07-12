#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
const int INF=5e8;
const int MAXV=5e3+50;
const int MAXE=1e5+50;
int V;
struct edge{int to,cost;};
vector<edge> G[MAXV];
typedef pair<int,int> P;
int d[MAXV];
void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P> > que;
    fill(d,d+V+1,INF);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty()){
        P t=que.top();
        que.pop();
        int v=t.second;
        if(d[v]<t.first)continue;
        for(int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int d2[MAXV];
int main(){
    int R;
    scanf("%d%d",&V,&R);
    for(int i=1;i<=R;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        G[x].push_back(edge{y,z});
        G[y].push_back(edge{x,z});
    }
    dijkstra(1);
    for(int i=1;i<=V;i++)d2[i]=d[i];
    dijkstra(V);
    int ans=INF;
    for(int i=1;i<=V;i++){
        for(int j=0;j<G[i].size();j++){
            edge e=G[i][j];
            int w=e.cost+d2[i]+d[e.to];
            if(w==d2[V])continue;
            ans=min(ans,w);
        }
    }
    printf("%d\n",ans);
    return 0;
}
