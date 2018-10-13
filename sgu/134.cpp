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
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=16000+10;
int tot;
int n;
int head[MAXN];
struct Edge{
    int v,nxt;
    Edge(){}
    Edge(int v,int nxt):v(v),nxt(nxt){}
}edge[MAXN<<1];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v){
    edge[tot]=Edge(v,head[u]);
    head[u]=tot++;
}
int mx=0x3f3f3f3f;
int ans[MAXN];
int sz[MAXN];
int cnt=0;
void dfs(int u,int p){
    sz[u]=1;
    int now=1;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p)continue;
        dfs(v,u);
        now=max(now,sz[v]);
        sz[u]+=sz[v];
    }
    now=max(now,n-sz[u]);
    if(now==mx||cnt==0){
        ans[++cnt]=u;
    }else if(now<mx){
        mx=now;
        cnt=0;
        ans[++cnt]=u;
    }
}
int main(){
    scanf("%d",&n);
    int m=n-1;
    init();
    while(m--){
        int u,v;
        scanf("%d%d",&u,&v);
        add_edge(u,v);
        add_edge(v,u);
    }
    dfs(1,-1);
    sort(ans+1,ans+1+cnt);
    printf("%d %d\n",mx,cnt);
    for(int i=1;i<=cnt;i++){
        printf("%d ",ans[i]);
    }
    return 0;
}
