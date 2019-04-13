#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=1e5+10;
int tot;
int head[MAXN];
struct Edge{
    int v,nxt,val,id;
}edge[MAXN<<1];
void init(){
    tot=0;
    memset(head,-1,sizeof(head));
}
void add_edge(int u,int v,int val,int id){
    edge[tot]=Edge{v,head[u],val,id};
    head[u]=tot++;
}
int top[MAXN],deep[MAXN],sz[MAXN],fa[MAXN],hv[MAXN],idx[MAXN],val[MAXN],eid[MAXN];
int b[MAXN];
void dfs1(int u,int p){
    sz[u]=1;
    int mx=0;
    for(int i=head[u];~i;i=edge[i].nxt){
        int v=edge[i].v;
        if(v==p)continue;
        fa[v]=u;
        deep[v]=deep[u]+1;
        val[v]=edge[i].val;
        dfs1(v,u);
        eid[edge[i].id]=v;
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
int tree[MAXN<<2],add[MAXN<<2],change[MAXN<<2];
void push_up(int rt){
    tree[rt]=max(tree[lson],tree[rson]);
}
void push_down(int rt){
    if(change[rt]!=-1){
        tree[lson]=tree[rson]=change[lson]=change[rson]=change[rt];
        add[lson]=add[rson]=0;
        change[rt]=-1;
    }
    if(add[rt]!=0){
        tree[lson]+=add[rt];
        tree[rson]+=add[rt];
        add[lson]+=add[rt];
        add[rson]+=add[rt];
        add[rt]=0;
    }
}
void build(int l,int r,int rt){
    add[rt]=0;
    change[rt]=-1;
    if(l==r){
        tree[rt]=b[l];
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
void Add(int L,int R,int val,int l,int r,int rt){
    if(L<=l&&r<=R){
        add[rt]+=val;
        tree[rt]+=val;
        return;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(mid>=L)Add(L,R,val,l,mid,lson);
    if(mid+1<=R)Add(L,R,val,mid+1,r,rson);
    push_up(rt);
}
void Change(int L,int R,int val,int l,int r,int rt){
    if(L<=l&&r<=R){
        change[rt]=val;
        tree[rt]=val;
        add[rt]=0;
        return;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(mid>=L)Change(L,R,val,l,mid,lson);
    if(mid+1<=R)Change(L,R,val,mid+1,r,rson);
    push_up(rt);
}
int query(int L,int R,int l,int r,int rt){
//    cout<<l<<" "<<r<<endl;
    if(L<=l&&r<=R){
//        cout<<tree[rt]<<"   --"<<endl;
        return tree[rt];
    }
    push_down(rt);
    int mid=(l+r)>>1;
    int res=0;
    if(mid>=L)res=max(res,query(L,R,l,mid,lson));
    if(mid+1<=R)res=max(res,query(L,R,mid+1,r,rson));
    return res;
}
char op[10];
int main(){
    int n;
    scanf("%d",&n);
    init();
    rep(i,1,n-1){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add_edge(x,y,z,i);
        add_edge(y,x,z,i);
    }
    dfs1(1,-1);
    tot=0;
    dfs2(1,-1,1);
    rep(i,1,n){
        b[idx[i]]=val[i];
    }
    //cout<<"11"<<endl;
    build(1,n,1);
    //cout<<"22"<<endl;
//    rep(i,1,n){
//        //cout<<b[i]<<endl;
//        cout<<query(idx[i],idx[i],1,n,1)<<" ";
//    }
//    cout<<endl;
    while(scanf("%s",op)){
        if(op[1]=='t')break;//Stop
        if(op[1]=='d'){//Add
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            int w=lca(x,y);
            while(top[x]!=top[w]){
                Add(idx[top[x]],idx[x],z,1,n,1);
                x=fa[top[x]];
            }
            if(x!=w){
                Add(idx[w]+1,idx[x],z,1,n,1);
            }
            while(top[y]!=top[w]){
                Add(idx[top[y]],idx[y],z,1,n,1);
                y=fa[top[y]];
            }
            if(y!=w){
                Add(idx[w]+1,idx[y],z,1,n,1);
            }
        }else if(op[1]=='a'){//Max
            int x,y;
            scanf("%d%d",&x,&y);
            int res=0;
            int w=lca(x,y);
//            cout<<w<<endl;
            while(top[x]!=top[w]){
                res=max(res,query(idx[top[x]],idx[x],1,n,1));
                x=fa[top[x]];
            }
            if(x!=w){
                res=max(res,query(idx[w]+1,idx[x],1,n,1));
            }
//            cout<<res<<endl;
            while(top[y]!=top[w]){
                res=max(res,query(idx[top[y]],idx[y],1,n,1));
                y=fa[top[y]];
            }
            if(y!=w){
                res=max(res,query(idx[w]+1,idx[y],1,n,1));
            }
            printf("%d\n",res);
        }else if(op[1]=='o'){//Cover
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            int w=lca(x,y);
            while(top[x]!=top[w]){
                Change(idx[top[x]],idx[x],z,1,n,1);
                x=fa[top[x]];
            }
            if(x!=w){
                Change(idx[w]+1,idx[x],z,1,n,1);
            }
            while(top[y]!=top[w]){
                Change(idx[top[y]],idx[y],z,1,n,1);
                y=fa[top[y]];
            }
            if(y!=w){
                Change(idx[w]+1,idx[y],z,1,n,1);
            }
        }else if(op[1]=='h'){//Change
            int x,y;
            scanf("%d%d",&x,&y);
            Change(idx[eid[x]],idx[eid[x]],y,1,n,1);
        }
    }
    return 0;
}
