#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
typedef long long ll;
const int MAXN=1e6+10;
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
int top[MAXN],sz[MAXN],deep[MAXN],hv[MAXN],fa[MAXN],idx[MAXN];
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
int a[MAXN],b[MAXN];
ll tree[MAXN<<2],lazy[MAXN<<2];
void push_up(int rt){
    tree[rt]=tree[lson]+tree[rson];
}
void push_down(int l,int r,int rt){
    if(lazy[rt]!=0){
        lazy[lson]+=lazy[rt];
        lazy[rson]+=lazy[rt];
        int mid=(l+r)>>1;
        tree[lson]+=1LL*(mid-l+1)*lazy[rt];
        tree[rson]+=1LL*(r-(mid+1)+1)*lazy[rt];
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
void update(int L,int R,ll val,int l,int r,int rt){
    if(L<=l&&r<=R){
        lazy[rt]+=val;
        tree[rt]+=1LL*(r-l+1)*val;
        return;
    }
    push_down(l,r,rt);
    int mid=(l+r)>>1;
    if(mid>=L)update(L,R,val,l,mid,lson);
    if(mid+1<=R)update(L,R,val,mid+1,r,rson);
    push_up(rt);
}
ll query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return tree[rt];
    }
    push_down(l,r,rt);
    int mid=(l+r)>>1;
    ll res=0;
    if(mid>=L)res+=query(L,R,l,mid,lson);
    if(mid+1<=R)res+=query(L,R,mid+1,r,rson);
    return res;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,n){
        scanf("%d",&a[i]);
    }
    init();
    rep(i,1,n-1){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    dfs1(1,-1);
    tot=0;
    dfs2(1,-1,1);
    rep(i,1,n){
        b[idx[i]]=a[i];
    }
    build(1,n,1);
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            scanf("%d%d",&x,&y);
            update(idx[x],idx[x],y,1,n,1);
        }else if(op==2){
            int x,y;
            scanf("%d%d",&x,&y);
            update(idx[x],idx[x]+sz[x]-1,y,1,n,1);
        }else if(op==3){
            int x;
            scanf("%d",&x);
            ll res=0;
            while(top[x]!=1){
                res+=query(idx[top[x]],idx[x],1,n,1);
                x=fa[top[x]];
            }
            res+=query(1,idx[x],1,n,1);
            printf("%lld\n",res);
        }
    }
    return 0;
}
