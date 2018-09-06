#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
const int MAXV=1e3+10;
const int MAXE=1e6+10;
int n,m;
int G[MAXV][MAXV];
void init(){
    clr(G,-1);
    rep(i,1,n)G[i][i]=0;
}
void add_edge(int u,int v,int c){
    if(G[u][v]==-1)G[u][v]=G[v][u]=c;
    else G[u][v]=G[v][u]=min(G[u][v],c);
}
int d[MAXV];
void dij(int s){
    priority_queue<pii ,vector<pii >,greater<pii > > pque;
    clr(d,-1);
    d[s]=0;
    pque.push(mp(0,s));
    while(!pque.empty()){
        pii t=pque.top();
        pque.pop();
        int u=t.se;
        if(d[u]!=-1&&d[u]<t.fi)continue;
        for(int i=1;i<=n;i++)if(G[u][i]!=-1){
            if(d[i]==-1||d[i]>d[u]+G[u][i]){
                d[i]=d[u]+G[u][i];
                pque.push(mp(d[i],i));
            }
        }
    }
}
namespace go{
    int tot;
    int head[MAXV],indec[MAXV];
    struct Edge{
        int v,nxt;
        Edge(){}
        Edge(int v,int nxt):v(v),nxt(nxt){}
    }edge[MAXE];
    void init(){
        tot=0;
        clr(head,-1);
        clr(indec,0);
    }
    void add_edge(int u,int v){
        edge[tot]=Edge(v,head[u]);
        indec[v]++;
        head[u]=tot++;
    }
    int ans[MAXV];
    int fun(){
        clr(ans,0);
        ans[2]=1;
        queue<int> que;
        que.push(2);
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int i=head[u];~i;i=edge[i].nxt){
                int v=edge[i].v;
                ans[v]+=ans[u];
                if(--indec[v]==0)que.push(v);
            }
        }
        return ans[1];
    }
};
int main(){
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        init();
        rep(i,1,m){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            add_edge(u,v,c);
        }
        dij(2);
        go::init();
        rep(i,1,n)rep(j,1,n){
            if(d[i]!=-1&&d[i]<d[j]&&G[i][j]!=-1)go::add_edge(i,j);
        }
        printf("%d\n",go::fun());
    }
    return 0;
}
