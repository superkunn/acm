#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=3e5+10;
int a[MAXN];
int tot;
int head[MAXN];
struct Edge{
    int v,nxt;
}edge[MAXN<<1];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v){
    edge[tot]=Edge{v,head[u]};
    head[u]=tot++;
}
int sz[MAXN],deep[MAXN],fa[MAXN],idx[MAXN],top[MAXN],hv[MAXN],ans[MAXN];
void dfs1(int u,int p){
    sz[u]=1;
    int mx=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p)continue;
        fa[v]=u;
        deep[v]=deep[u]+1;
        dfs1(v,u);
        if(sz[v]>mx){
            mx=sz[v];
            hv[u]=v;
        }
        sz[u]+=sz[v];
    }
}
void dfs2(int u,int p,int tp){
    top[u]=tp;
    idx[u]=++tot;
    if(sz[u]==1)return;
    dfs2(hv[u],u,tp);
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p||v==hv[u])continue;
        dfs2(v,u,v);
    }
}
int lca(int u,int v){
    while(top[u]!=top[v]){
        if(deep[top[u]]<deep[top[v]]){
            v=fa[top[v]];
        }else{
            u=fa[top[u]];
        }
    }
    if(deep[u]<deep[v])return u;
    else return v;
}
void update(int x,int y){
    while(top[x]!=top[y]){
        ans[idx[top[x]]]++;
        ans[idx[x]+1]--;
        x=fa[top[x]];
    }
    ans[idx[y]]++;
    ans[idx[x]+1]--;
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d",&a[i]);
    }
    init();
    rep(i,2,n){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(1,-1);
    tot=0;
    dfs2(1,-1,1);
    rep(i,2,n){
        int w=lca(a[i],a[i-1]);
        update(a[i],w);
        update(a[i-1],w);

        ans[idx[a[i]]]--;
        ans[idx[a[i]]+1]++;

        ans[idx[w]]--;
        ans[idx[w]+1]++;
    }
    rep(i,1,n){
        ans[i]+=ans[i-1];
    }
    rep(i,1,n){
        printf("%d\n",ans[idx[i]]);
    }
    return 0;
}
