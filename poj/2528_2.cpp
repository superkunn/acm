#include<cstdio>
#include<algorithm>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=2e4+10;
struct node{
    int v,id;
}no[MAXN];
bool cmp1(node x,node y){
    return x.v<y.v;
}
int a[MAXN];
int tree[MAXN<<2];
bool vis[MAXN];
int ans;
void push_down(int rt){
    if(tree[rt]==0)return;
    tree[lson]=tree[rson]=tree[rt];
    tree[rt]=0;
}
void build(int l,int r,int rt){
    tree[rt]=0;
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
}
void update(int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[rt]=v;
        return;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(mid>=L)update(L,R,v,l,mid,lson);
    if(mid+1<=R)update(L,R,v,mid+1,r,rson);
}
void query(int l,int r,int rt){
    if(tree[rt]){
        if(!vis[tree[rt]]){
            vis[tree[rt]]=true;
            ans++;
        }
        return;
    }
    if(l==r){
        return;
    }
    int mid=(l+r)>>1;
    query(l,mid,lson);
    query(mid+1,r,rson);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d%d",&no[i].v,&no[i+n].v);
            no[i].id=i;
            no[i+n].id=i+n;
        }
        sort(no+1,no+1+2*n,cmp1);
        int cnt=1;
        a[no[1].id]=1;
        rep(i,2,2*n){
            if(no[i].v!=no[i-1].v){
                cnt++;
            }
            a[no[i].id]=cnt;
        }
        build(1,cnt,1);
        rep(i,1,n){
            update(a[i],a[i+n],i,1,cnt,1);
            vis[i]=false;
        }
        ans=0;
        query(1,cnt,1);
        printf("%d\n",ans);
    }
    return 0;
}
