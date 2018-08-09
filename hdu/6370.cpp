#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
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
const int MAXN=1e5+5;
int T,n,x,ans,vis[MAXN];
char op[10];
struct DSU{
    int p[MAXN];
    void init(int n){rep(i,1,n)p[i]=i;}
    int findp(int x){return x==p[x]?x:p[x]=findp(p[x]);}
    void unite(int x,int y){x=findp(x);y=findp(y);if(x!=y)p[x]=y;}
    bool same(int x,int y){return findp(x)==findp(y);}
}dsu;
int head[MAXN];
int tot;
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):v(v),nxt(nxt){}
}edge[MAXN];
struct node{
    int u,v;
    node(){}
    node(int u,int v):u(u),v(v){}
}no[MAXN];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
void dfs(int x){
    if(vis[x])return;
    ans++;
    vis[x]=1;
    for(int i=head[x];i!=-1;i=edge[i].nxt){
        dfs(edge[i].v);
    }
}
int work(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        dsu.init(n);
        int index=0;
        rep(i,1,n){
            scanf("%d%s",&x,op);
            if(op[0]=='v'){
                add_edge(x,i);
                dsu.unite(i,x);
            }else{
                no[++index]=node(i,x);
            }
        }
        ans=0;
        memset(vis,0,sizeof(vis));
        rep(i,1,index){
            if(dsu.same(no[i].u,no[i].v)){
                dfs(no[i].v);
            }
        }
        printf("0 %d\n",ans);
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
