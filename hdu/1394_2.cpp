#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=5e3+10;
int a[MAXN];
int tree[MAXN];
void push_up(int rt){
    tree[rt]=tree[lson]+tree[rson];
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=0;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,lson);
    build(mid+1,r,rson);
    push_up(rt);
}
void update(int pos,int l,int r,int rt){
    if(l==r){
        tree[rt]++;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)update(pos,l,mid,lson);
    if(pos>mid)update(pos,mid+1,r,rson);
    push_up(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return tree[rt];
    }
    int mid=(l+r)>>1;
    int res=0;
    if(mid>=L)res+=query(L,R,l,mid,lson);
    if(mid+1<=R)res+=query(L,R,mid+1,r,rson);
    return res;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        int sum=0;
        rep(i,1,n){
            scanf("%d",&a[i]);
            a[i]++;
        }
        build(1,n,1);
        rep(i,1,n){
            sum+=query(a[i],n,1,n,1);
            update(a[i],1,n,1);
        }
        int ans=sum;
        rep(i,1,n){
            sum-=a[i]-1;
            sum+=n-a[i];
            ans=min(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}
