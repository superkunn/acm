#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=30000+10;
const int INF=0x3f3f3f3f;
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
int sz[MAXN],top[MAXN],hv[MAXN],idx[MAXN],deep[MAXN],fa[MAXN];
void dfs1(int u,int p){
    sz[u]=1;
    int mx=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p)continue;
        deep[v]=deep[u]+1;
        fa[v]=u;
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
int sum[MAXN<<2],mx[MAXN<<2],a[MAXN];
void push_up(int rt){
    sum[rt]=sum[lson]+sum[rson];
    mx[rt]=max(mx[lson],mx[rson]);
}
void build(int l,int r,int rt){
    if(l==r){
        sum[rt]=mx[rt]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
void update(int pos,int val,int l,int r,int rt){
    if(l==r){
        mx[rt]=val;
        sum[rt]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(pos,val,l,mid,lson);
    }else{
        update(pos,val,mid+1,r,rson);
    }
    push_up(rt);
}
int getsum(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return sum[rt];
    }
    int mid=(l+r)>>1;
    int res=0;
    if(mid>=L)res+=getsum(L,R,l,mid,lson);
    if(mid+1<=R)res+=getsum(L,R,mid+1,r,rson);
    return res;
}
int getmax(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return mx[rt];
    }
    int mid=(l+r)>>1;
    int res=-INF;
    if(mid>=L)res=max(res,getmax(L,R,l,mid,lson));
    if(mid+1<=R)res=max(res,getmax(L,R,mid+1,r,rson));
    return res;
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
char op[20];
int main(){
    int n;
    scanf("%d",&n);
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
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        a[idx[i]]=x;
    }
    build(1,n,1);
    int q;
    scanf("%d",&q);
    while(q--){
        int x,y;
        scanf("%s%d%d",op,&x,&y);
        if(op[1]=='M'){
            int w=lca(x,y);
            int res=-INF;
            while(top[x]!=top[w]){
                res=max(res,getmax(idx[top[x]],idx[x],1,n,1));
                x=fa[top[x]];
            }
            res=max(res,getmax(idx[w],idx[x],1,n,1));
            while(top[y]!=top[w]){
                res=max(res,getmax(idx[top[y]],idx[y],1,n,1));
                y=fa[top[y]];
            }
            res=max(res,getmax(idx[w],idx[y],1,n,1));
            printf("%d\n",res);

        }else if(op[1]=='S'){
            int w=lca(x,y);
            int res=0;
            while(top[x]!=top[w]){
                res+=getsum(idx[top[x]],idx[x],1,n,1);
                x=fa[top[x]];
            }
            res+=getsum(idx[w],idx[x],1,n,1);
            while(top[y]!=top[w]){
                res+=getsum(idx[top[y]],idx[y],1,n,1);
                y=fa[top[y]];
            }
            res+=getsum(idx[w],idx[y],1,n,1);
            res-=getsum(idx[w],idx[w],1,n,1);
            printf("%d\n",res);
        }else{
            update(idx[x],y,1,n,1);
        }
    }
    return 0;
}
