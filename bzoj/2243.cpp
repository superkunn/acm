#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=1e5+10;
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
int top[MAXN],sz[MAXN],fa[MAXN],hv[MAXN],deep[MAXN],idx[MAXN];
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
int tree[MAXN<<2],lazy[MAXN<<2],tl[MAXN<<2],tr[MAXN<<2],b[MAXN];
void push_up(int rt){
    tree[rt]=tree[lson]+tree[rson];
    if(tr[lson]==tl[rson])tree[rt]--;
    tl[rt]=tl[lson];
    tr[rt]=tr[rson];
}
void push_down(int rt){
    if(lazy[rt]!=-1){
        lazy[lson]=lazy[rson]=lazy[rt];
        tl[lson]=tl[rson]=tr[lson]=tr[rson]=lazy[rt];
        tree[lson]=tree[rson]=1;
        lazy[rt]=-1;
    }
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=1;
        lazy[rt]=tl[rt]=tr[rt]=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return tree[rt];
    }
    int mid=(l+r)>>1;
    push_down(rt);
    if(mid>=L){
        if(mid+1<=R){
            return query(L,R,l,mid,lson)+query(L,R,mid+1,r,rson)-(tr[lson]==tl[rson]);
        }else{
            return query(L,R,l,mid,lson);
        }
    }else{
        if(mid+1<=R)return query(L,R,mid+1,r,rson);
    }
}
int getcol(int pos,int l,int r,int rt){
    if(l==r){
        return lazy[rt];
    }
    int mid=(l+r)>>1;
    push_down(rt);
    if(pos<=mid){
        getcol(pos,l,mid,lson);
    }else{
        getcol(pos,mid+1,r,rson);
    }
}
void update(int L,int R,int val,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[rt]=1;
        lazy[rt]=tl[rt]=tr[rt]=val;
        return;
    }
    int mid=(l+r)>>1;
    push_down(rt);
    if(mid>=L)update(L,R,val,l,mid,lson);
    if(mid+1<=R)update(L,R,val,mid+1,r,rson);
    push_up(rt);
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
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
    rep(i,1,n){
        b[idx[i]]=a[i];
    }
    memset(lazy,-1,sizeof(lazy));
    build(1,n,1);
    while(q--){
        char op[5];
        scanf("%s",op);
        if(op[0]=='Q'){
            int res=0;
            int x,y;
            scanf("%d%d",&x,&y);
            int w=lca(x,y);
            int r=-1;
            while(top[x]!=top[w]){
                res+=query(idx[top[x]],idx[x],1,n,1);
                if(r==getcol(idx[x],1,n,1))res--;
                r=getcol(idx[top[x]],1,n,1);
                x=fa[top[x]];
            }
            res+=query(idx[w],idx[x],1,n,1);
            if(r==getcol(idx[x],1,n,1))res--;
            int l=-1;
            while(top[y]!=top[w]){
                res+=query(idx[top[y]],idx[y],1,n,1);
                if(l==getcol(idx[y],1,n,1))res--;
                l=getcol(idx[top[y]],1,n,1);
                y=fa[top[y]];
            }
            if(y!=w){
                res+=query(idx[w]+1,idx[y],1,n,1);
                if(l==getcol(idx[y],1,n,1))res--;
                l=getcol(idx[w]+1,1,n,1);
            }
            if(l==getcol(idx[w],1,n,1))res--;
            printf("%d\n",res);
        }else{
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            int w=lca(x,y);
            while(top[x]!=top[w]){
                update(idx[top[x]],idx[x],z,1,n,1);
                x=fa[top[x]];
            }
            update(idx[w],idx[x],z,1,n,1);
            while(top[y]!=top[w]){
                update(idx[top[y]],idx[y],z,1,n,1);
                y=fa[top[y]];
            }
            update(idx[w],idx[y],z,1,n,1);
        }
    }
    return 0;
}
/*
10 100
1 1 1 1 1 1 1 1 1 1
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
Q 1 10
C 7 8 2
Q 7 8

*/

