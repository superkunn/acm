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
void update(int pos,int val,int l,int r,int rt){
    if(l==r){
        tree[rt]=val;
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
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return tree[rt];
    }
    int mid=(l+r)>>1;
    int res=0;
    if(mid>=L){
        res=max(res,query(L,R,l,mid,lson));
    }
    if(mid+1<=R){
        res=max(res,query(L,R,mid+1,r,rson));
    }
    return res;
}
int main(){
    int n=200000;
    int m,d,len=0;
    scanf("%d%d",&m,&d);
    int t=0;
    while(m--){
        char op[5];
        int x;
        scanf("%s%d",op,&x);
        if(op[0]=='A'){
            x=x+t;
            if(x<0){
                x+=d;
            }else{
                x%=d;
            }
            len++;
            update(len,x,1,n,1);
        }else{
            printf("%d\n",t=query(len-x+1,len,1,n,1));
        }
    }
    return 0;
}
