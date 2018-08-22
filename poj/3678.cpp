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
const int MAXV=2e3+10;
const int MAXE=4e6+10;
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
char op[10];
int work(){
    int N,M;
    scanf("%d%d",&N,&M);
    init();
    rep(i,1,M){
        int a,b,c;
        scanf("%d%d%d%s",&a,&b,&c,op);
        if(op[0]=='A'){
            if(c==1){
                add_var(1,a);
                add_var(1,b);
            }else{
                add_clause(0,a,0,b);
            }
        }else if(op[0]=='O'){
            if(c==1){
                add_clause(1,a,1,b);
            }else{
                add_var(0,a);
                add_var(0,b);
            }
        }else{
            if(c==1){
                add_edge(a<<1|1,b<<1);
                add_edge(a<<1,b<<1|1);
                add_edge(b<<1|1,a<<1);
                add_edge(b<<1,a<<1|1);
            }else{
                add_edge(a<<1|1,b<<1|1);
                add_edge(a<<1,b<<1);
                add_edge(b<<1|1,a<<1|1);
                add_edge(b<<1,a<<1);
            }
        }
    }
    kscc(2*N);
    rep(i,0,N-1){
        if(Belong[i<<1]==Belong[i<<1|1]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
