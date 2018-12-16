#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
const int MAXN=2e5+10;
int tree[MAXN<<2];
void push_up(int rt){
    tree[rt]=max(tree[lson],tree[rson]);
}
void build(int v,int l,int r,int rt){
    if(l==r){
        tree[rt]=v;
        return;
    }
    int mid=(l+r)>>1;
    build(v,l,mid,lson);
    build(v,mid+1,r,rson);
    push_up(rt);
}
int query(int v,int l,int r,int rt){
    if(l==r){
        tree[rt]-=v;
        return l;
    }
    int mid=(l+r)>>1;
    int res;
    if(tree[lson]>=v)res=query(v,l,mid,lson);
    else res=query(v,mid+1,r,rson);
    push_up(rt);
    return res;
}
int main(){
    int h,w,n;
    while(~scanf("%d%d%d",&h,&w,&n)){
        build(w,1,min(h,n),1);
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            if(tree[1]<x){
                puts("-1");
            }else{
                printf("%d\n",query(x,1,min(h,n),1));
            }
        }
    }
    return 0;
}
