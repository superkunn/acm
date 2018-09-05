#include<bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
//0 base !
//if （x V （！y））then add_clause(1,x,0,y)
//if  x then add_var(1,x)
const int MAXV=2e5;
const int MAXE=2e7+5;
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
void add_clause(int xv,int x,int yv,int y){
    x=x<<1|xv;
    y=y<<1|yv;
    add_edge(x^1,y);
    add_edge(y^1,x);
}
void add_var(int xv,int x){
    x=x<<1|xv;
    add_edge(x^1,x);
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
    rep(i,0,V-1)if(!vis[i])dfs(i);
    clr(vis,0);
    per(i,top,1){
        int v=stk[i];
        if(!vis[v])rdfs(v,++scc);
    }
}
int x[MAXV][2];
int n;
bool check(int v){
    init();
    rep(i,0,n-1)rep(a,0,1)
        rep(j,i+1,n-1)rep(b,0,1)
            if(abs(x[i][a]-x[j][b])<v)add_clause(a,i,b,j);
    kscc(2*n);
    rep(i,0,n-1){
        if(Belong[i<<1]==Belong[i<<1|1])return false;
    }
    return true;
}
int main(){
    while(~scanf("%d",&n)){
        int l=0,r=1e7+10;
        rep(i,0,n-1){
            rep(j,0,1){
                scanf("%d",&x[i][j]);
            }
        }
        while(l<r){
            int mid=l+(r-l+1)/2;
            if(check(mid)){
                l=mid;
            }else r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}
