#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXV=1<<12;
const int MAXE=1<<14;
int tot,scc,head[MAXV],rhead[MAXV],Belong[MAXV];
int stk[MAXV],top;
bool vis[MAXV];
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
int N,M;
int idx[MAXV<<1];
int uu[MAXE],vv[MAXE];
bool check(int x){
    init();
    rep(i,1,x){
        if(uu[i]==vv[i]){
            add_edge(idx[uu[i]]^1,idx[uu[i]]);
        }else{
            add_edge(idx[uu[i]]^1,idx[vv[i]]);
            add_edge(idx[vv[i]]^1,idx[uu[i]]);
        }
    }
    kscc(N*2);
    rep(i,0,N-1){
        if(Belong[i<<1]==Belong[i<<1|1])return false;
    }
    return true;
}
int work(){
    while(scanf("%d%d",&N,&M),N+M){
        rep(i,0,N-1){
            int x,y;
            scanf("%d%d",&x,&y);
            idx[x]=i<<1;
            idx[y]=i<<1|1;
        }
        rep(i,1,M){
            scanf("%d%d",&uu[i],&vv[i]);
        }
        int l=1,r=M,ans=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
