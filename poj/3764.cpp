#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
const int MAXV=1e5+10;
const int MAXN=4e6+10;
int head[MAXV];
int tot;
struct Edge{
    int v,w,nxt;
    Edge(){}
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}edge[MAXV<<1];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int w){
    edge[tot]=Edge(v,w,head[u]);
    head[u]=tot++;
}
int w[MAXV];
void dfs(int u,int p){
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p)continue;
        w[v]=w[u]^edge[i].w;
        dfs(v,u);
    }
}
int trie[MAXN][2];
int cnt=1;
void Insert(int x){
    int p=1;
    for(int i=30;i>=0;i--){
        int now=(x>>i)&1;
        if(trie[p][now]==0)trie[p][now]=++cnt;
        p=trie[p][now];
    }
}
int query(int x){
    int ans=0;
    int p=1;
    for(int i=30;i>=0;i--){
        int now=(x>>i)&1;
        if(trie[p][now^1]!=0){
            ans+=1<<i;
            p=trie[p][now^1];
        }else{
            p=trie[p][now];
        }
    }
    return ans;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        init();
        for(int i=1;i<n;i++){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            add_edge(v,u,w);
        }
        dfs(0,-1);
        int ans=0;
        memset(trie,0,sizeof(trie));
        Insert(w[0]);
        for(int i=1;i<n;i++){
            ans=max(ans,query(w[i]));
            Insert(w[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
