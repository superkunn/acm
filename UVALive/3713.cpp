#include<bits/stdc++.h>
using namespace std;
#define clr(a,x) memset(a,x,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
//0 base !
//if （x V （！y））then add_clause(1,x,0,y)
//if  x then add_var(1,x)
const int MAXV=2e5+10;
const int MAXE=1e6+5;
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
int x[MAXV],y[MAXV];
bool check(int n){
    rep(i,0,n-1)if(Belong[i<<1]==Belong[i<<1|1])return false;
    return true;
}
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m),n+m){
        double sum=0.0;
        rep(i,0,n-1){
            scanf("%d",&x[i]);
            sum+=x[i];
        }
        sum/=n;
        rep(i,0,n-1){
            if(x[i]>=sum)y[i]=1;
            else y[i]=2;
        }
        init();
        rep(i,1,m){
            int u,v;
            scanf("%d%d",&u,&v);
            u--;
            v--;
            if(u==v)continue;
            if(y[u]==y[v]){
                add_clause(1,u,1,v);
                add_clause(0,u,0,v);
            }else{
                add_clause(1,u,1,v);
            }
        }
        kscc(2*n);
        if(!check(n)){
            puts("No solution.");
            continue;
        }
        rep(i,0,n-1){
            if(Belong[i<<1|1]>Belong[i<<1]){
                if(x[i]>=sum){
                    puts("A");
                }else{
                    puts("B");
                }
            }else{
                puts("C");
            }
        }
    }
    return 0;
}
