#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define fi first
#define se second
const int MAXN=1e4+10;
typedef pair<int,int> pii;
vector<pii> G[MAXN];
int mx[MAXN],mxx[MAXN];
int ans[MAXN];
void dfs(int u,int p){
    for(auto x:G[u]){
        int v=x.fi;
        if(v==p)continue;
        int w=x.se;
        dfs(v,u);
        if(mx[v]+w>mx[u]){
            mxx[u]=mx[u];
            mx[u]=mx[v]+w;
        }else if(mx[v]+w>mxx[u]){
            mxx[u]=mx[v]+w;
        }
    }
}
void dfs2(int u,int p,int val){
    ans[u]=max(mx[u],val);
    for(auto x:G[u]){
        int v=x.fi;
        if(v==p)continue;
        int w=x.se;
        if(mx[v]+w==mx[u]){
            dfs2(v,u,max(mxx[u],val)+w);
        }else{
            dfs2(v,u,max(mx[u],val)+w);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,2,n){
        int x,y;
        scanf("%d%d",&x,&y);
        G[i].pb({x,y});
        G[x].pb({i,y});
    }
    dfs(1,-1);
    dfs2(1,-1,0);
    rep(i,1,n){
        printf("%d\n",ans[i]);
    }
    return 0;
}
