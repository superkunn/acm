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
const int MAXN=1e4+5;
const int MAXM=1e5+5;
int T,N,M;
queue<int> que;
int tot;
int head[MAXN],idec[MAXN],dp[MAXN];
struct Edge{
    int v,w,nxt;
    Edge(){}
    Edge(int v,int w,int nxt):v(v),w(w),nxt(nxt){}
}edge[MAXM];
void init(){
    tot=0;
    clr(head,-1);
}
void add_edge(int u,int v,int w){
    edge[tot]=Edge(v,w,head[u]);
    head[u]=tot++;
}
int topsort(){
    while(!que.empty())que.pop();
    int ans=0;
    rep(i,1,N)if(!idec[i])que.push(i);
    while(!que.empty()){
        int u=que.front();
        que.pop();
        ans=max(ans,dp[u]);
        for(int i=head[u];i!=-1;i=edge[i].nxt){
            int v=edge[i].v;
            dp[v]=max(dp[v],dp[u]+edge[i].w);
            if(--idec[v]==0)que.push(v);
        }
    }
    return ans;
}
int work(){
    scanf("%d",&T);
    while(T--){
        init();
        clr(idec,0);
        clr(dp,0);
        scanf("%d%d",&N,&M);
        while(M--){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(u,v,w);
            idec[v]++;
        }
        printf("%d\n",topsort());
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
