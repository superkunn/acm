#include<cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=5e5+10;
int cnt[MAXN],w[MAXN],a[MAXN];
char name[MAXN][15];
int tree[MAXN<<2];
void push_up(int rt){
    tree[rt]=tree[lson]+tree[rson];
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
void update(int pos,int l,int r,int rt){
    if(l==r){
        tree[rt]--;
        return;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(pos,l,mid,lson);
    else update(pos,mid+1,r,rson);
    push_up(rt);
}
int query(int v,int l,int r,int rt){
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(tree[lson]>=v)return query(v,l,mid,lson);
    else return query(v-tree[lson],mid+1,r,rson);
}
int main(){
    rep(i,1,500000){
        for(int j=i;j<=500000;j+=i){
            cnt[j]++;
        }
    }
    w[1]=1;
    rep(i,2,500000){
        if(cnt[i]>cnt[w[i-1]]){
            w[i]=i;
        }else{
            w[i]=w[i-1];
        }
    }
    int n,m;
    while(~scanf("%d%d",&n,&m)){
        build(1,n,1);
        rep(i,1,n){
            scanf("%s%d",name[i],&a[i]);
        }
        int k=w[n];
        int now=m;
        int pos=m;
        rep(i,1,k){
            if(i==k){
                printf("%s %d\n",name[pos],cnt[k]);
                break;
            }
            update(pos,1,n,1);
            if(a[pos]>0){
                now=(now-1+a[pos]-1)%tree[1]+1;
            }else{
                now=(now-(-a[pos])%tree[1]);
                while(now<=0)now+=tree[1];
                while(now>tree[1])now-=tree[1];
            }
            pos=query(now,1,n,1);
        }
    }
    return 0;
}
