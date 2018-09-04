#include<bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int MAXV=1e3+10;
const int MAXE=5e4+10;
int tot,scc,head[MAXV],rhead[MAXV],Belong[MAXV];
bool vis[MAXV];
int stk[MAXV],top;
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):v(v),nxt(nxt){}
}edge[MAXE],redge[MAXE];
void init(){
    tot=0;
    clr(head,-1);
    clr(rhead,-1);
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    redge[tot]=Edge(u,rhead[v]);
    head[u]=rhead[v]=tot++;
}
void dfs(int u){
    vis[u]=true;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(!vis[v])dfs(v);
    }
    stk[++top]=u;
}
void rdfs(int u,int k){
    vis[u]=true;
    Belong[u]=k;
    for(int i=rhead[u];~i;i=redge[i].nxt){
        int v=redge[i].v;
        if(!vis[v])rdfs(v,k);
    }
}
void kscc(int V){
    scc=top=0;
    clr(vis,0);
    rep(i,1,V)if(!vis[i])dfs(i);
    clr(vis,0);
    per(i,top,1){
        int v=stk[i];
        if(!vis[v])rdfs(v,++scc);
    }
}
int x[MAXE],y[MAXE];
namespace go{
    int w[MAXV];
    int ans[MAXV];
    int indec[MAXV];
    int tot;
    int head[MAXV];
    struct Edge{
        int v,nxt;
        Edge(){}
        Edge(int v,int nxt):v(v),nxt(nxt){}
    }edge[MAXE];
    void init(){
        tot=0;
        clr(head,-1);
        clr(indec,0);
        clr(ans,0);
    }
    void add_edge(int u,int v){
        edge[tot]=Edge(v,head[u]);
        head[u]=tot++;
    }
    void fun(int u,int v){
        indec[u]++;
        add_edge(v,u);
    }
    int work(int n){
        queue<int> que;
        rep(i,1,n){
            if(indec[i]==0)que.push(i),ans[i]=w[i];
        }
        while(!que.empty()){
            int u=que.front();
            que.pop();
            for(int i=head[u];~i;i=edge[i].nxt){
                int v=edge[i].v;
                ans[v]=max(ans[v],w[v]+ans[u]);
                if(--indec[v]==0)que.push(v);
            }
        }
        int res=0;
        rep(i,1,n){
            res=max(res,ans[i]);
        }
        return res;
    }
};
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        init();
        rep(i,1,m){
            scanf("%d%d",&x[i],&y[i]);
            add_edge(x[i],y[i]);
        }
        kscc(n);
        clr(go::w,0);
        rep(i,1,n){
            go::w[Belong[i]]++;
        }
        go::init();
        rep(i,1,m){
            int u=Belong[x[i]];
            int v=Belong[y[i]];
            if(u==v)continue;
            go::fun(u,v);
        }
        printf("%d\n",go::work(scc));
    }

    return 0;
}
