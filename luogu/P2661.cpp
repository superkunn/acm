#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
const int MAXN=2e5+233;
int vis[MAXN];
int G[MAXN];
int ans=1e9;
int d[MAXN];
int f[MAXN];
void dfs(int u,int dep){
    if(f[u])return;
    f[u]=true;
    int v=G[u];
    if(d[v]!=0){
        ans=min(ans,dep-d[v]+1);
    }else{
        d[v]=d[u]+1;
        dfs(v,dep+1);
        d[v]=0;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        G[i]=x;
        vis[x]=1;
    }
    rep(i,1,n){
        if(vis[i]==0){
            d[i]=1;
            dfs(i,1);
        }
    }
    rep(i,1,n){
        if(f[i]==0){
            dfs(i,1);
        }
    }
    printf("%d",ans);
    return 0;
}
