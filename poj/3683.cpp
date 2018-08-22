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
const int MAXV=1e5;
const int MAXE=3e6+5;
int V,tot,scc,head[MAXV],rhead[MAXV],Belong[MAXV];
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
    for(int i=head[u];i!=-1;i=edge[i].nxt){
        int v=edge[i].v;
        if(!vis[v])dfs(v);
    }
    stk[++top]=u;
}
void rdfs(int u,int k){
    vis[u]=true;
    Belong[u]=k;
    for(int i=rhead[u];i!=-1;i=redge[i].nxt){
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
int st[MAXV],ed[MAXV],d[MAXV];
char tm[10];
int fun(){
    int res=0;
    int h=(tm[0]-'0')*10+tm[1]-'0';
    res=h*60;
    res+=(tm[3]-'0')*10+tm[4]-'0';
    return res;
}
int work(){
    int n;
    scanf("%d",&n);
    rep(i,0,n-1){
        scanf("%s",tm);
        st[i]=fun();
        scanf("%s",tm);
        ed[i]=fun();
        scanf("%d",&d[i]);
    }
    init();
    rep(i,0,n-1){
        rep(j,0,i-1){
            if(min(st[i]+d[i],st[j]+d[j])>max(st[i],st[j])){
                add_clause(0,i,0,j);
            }
            if(min(st[i]+d[i],ed[j])>max(st[i],ed[j]-d[j])){
                add_clause(0,i,1,j);
            }
            if(min(ed[i],st[j]+d[j])>max(ed[i]-d[i],st[j])){
                add_clause(1,i,0,j);
            }
            if(min(ed[i],ed[j])>max(ed[i]-d[i],ed[j]-d[j])){
                add_clause(1,i,1,j);
            }
        }
    }
    kscc(2*n);
    rep(i,0,n-1){
        if(Belong[i<<1]==Belong[i<<1|1]){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    rep(i,0,n-1){
        if(Belong[i<<1|1]>Belong[i<<1]){
            printf("%02d:%02d %02d:%02d\n",st[i]/60,st[i]%60,(st[i]+d[i])/60,(st[i]+d[i])%60);
        }else{
            printf("%02d:%02d %02d:%02d\n",(ed[i]-d[i])/60,(ed[i]-d[i])%60,ed[i]/60,ed[i]%60);
        }
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
