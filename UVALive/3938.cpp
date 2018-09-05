#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
#define le l,m,lson
#define ri m+1,r,rson
#define mid m=(l+r)>>1
typedef long long ll;
const int MAXN=5e5+10;
ll x[MAXN];
ll sum(int l,int r){
    return x[r]-x[l-1];
}
struct node{
    int x,y,a,b,L,R;
    node(){}
    node(int x,int y,int a,int b,int L,int R):x(x),y(y),a(a),b(b),L(L),R(R){}
}tree[MAXN<<2];
node fun(node l,node r){
    node res;
    res.L=l.L;
    res.R=r.R;
    if(sum(l.x,l.y)>=sum(r.x,r.y)){
        res.x=l.x;
        res.y=l.y;
    }else{
        res.x=r.x;
        res.y=r.y;
    }

    if(sum(l.b,r.a)>sum(res.x,res.y)){
        res.x=l.b;
        res.y=r.a;
    }else if(sum(l.b,r.a)==sum(res.x,res.y)){
        if(l.b<res.x){
            res.x=l.b;
            res.y=r.a;
        }else if(l.b==res.x){
            if(r.a<res.y){
                res.x=l.b;
                res.y=r.a;
            }
        }
    }
    if(sum(res.L,l.a)>=sum(res.L,r.a)){
        res.a=l.a;
    }else{
        res.a=r.a;
    }

    if(sum(l.b,res.R)>=sum(r.b,res.R)){
        res.b=l.b;
    }else{
        res.b=r.b;
    }
    return res;
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=node(l,l,l,l,l,l);
        return;
    }
    int mid;
    build(le);
    build(ri);
    tree[rt]=fun(tree[lson],tree[rson]);
}
node query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R)return tree[rt];
    int mid;
    if(m>=L){
        node n1=query(L,R,le);
        if(m<R){
            node n2=query(L,R,ri);
            return fun(n1,n2);
        }else return n1;
    }
    if(m<R)return query(L,R,ri);
}
int main(){
    int n,m;
    int kase=0;
    while(~scanf("%d%d",&n,&m)){
        x[0]=0;
        rep(i,1,n){
            int w;
            scanf("%d",&w);
            x[i]=x[i-1]+w;
        }
        build(1,n,1);
        printf("Case %d:\n",++kase);
        while(m--){
            int l,r;
            scanf("%d%d",&l,&r);
            node ans=query(l,r,1,n,1);
            printf("%d %d\n",ans.x,ans.y);
        }
    }
    return 0;
}
