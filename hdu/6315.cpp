#include<bits/stdc++.h>
#define LL long long
using namespace std;
typedef long long ll;
const int MAXN=1e5+5;
//***************
const int INF=1e9;
int n,a[MAXN],q;
struct node{
    int l,r,id;
    int mm,lazy;
    void update(int x){
        mm+=x;
        lazy+=x;
    }
}tree[MAXN*4];
void push_up(int x){
    tree[x].mm=min(tree[x<<1].mm,tree[x<<1|1].mm);
    tree[x].id=tree[x<<1].mm<tree[x<<1|1].mm?tree[x<<1].id:tree[x<<1|1].id;
}
void push_down(int x){
    int lazyval=tree[x].lazy;
    if(lazyval){
        tree[x<<1].update(lazyval);
        tree[x<<1|1].update(lazyval);
        tree[x].lazy=0;
    }
}
void build(int x,int l,int r){
    tree[x].l=l;
    tree[x].r=r;
    tree[x].mm=tree[x].lazy=0;
    if(l==r){
        if(l>n)tree[x].mm=INF;
        else tree[x].mm=a[l];
        tree[x].id=l;
    }
    else{
        int mid=(l+r)/2;
        build(x<<1,l,mid);
        build(x<<1|1,mid+1,r);
        push_up(x);
    }
}
void update(int x,int l,int r,int val){
    int L=tree[x].l;
    int R=tree[x].r;
    if(l<=L&&R<=r){
        tree[x].lazy+=val;
        tree[x].mm+=val;
    }else{
        push_down(x);
        int mid=(L+R)/2;
        if(l<=mid)update(x<<1,l,r,val);
        if(r>mid)update(x<<1|1,l,r,val);
        push_up(x);
    }
}
pair<int,int> query(int x,int l,int r){
    int L=tree[x].l;
    int R=tree[x].r;
    if(l<=L&&R<=r){
        return make_pair(tree[x].mm,tree[x].id);
    }else{
        push_down(x);
        int mid=(L+R)/2;
        pair<int,int> res;
        res.first=INF;
        if(l<=mid){
            pair<int,int> temp=query(x<<1,l,r);
            if(temp.first<res.first){
                res.first=temp.first;
                res.second=temp.second;
            }
        };
        if(r>mid){
            pair<int,int> temp=query(x<<1|1,l,r);
            if(temp.first<res.first){
                res.first=temp.first;
                res.second=temp.second;
            }
        }
        push_up(x);
        return res;
    }
}
//******************
struct BIT{
    int nn;
    ll c[MAXN<<1];
    void init(int _n){nn=_n;for(int i=0;i<=nn;i++)c[i]=0;}
    void add(int x){for(int i=x;i<=nn;i+=i&-i)c[i]++;}
    ll sum(int x){ll s=0;for(int i=x;i>0;i-=i&-i)s+=c[i];return s;}
}bit;
char s[10];
void check(int x,int y){
    for(int i=x;i<=y;i++){
        pair<int,int> pp=query(1,i,i);
        printf("%d %d\n",pp.first,pp.second);
    }
}
int main(){
    while(~scanf("%d%d",&n,&q)){
        bit.init(n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        build(1,1,n);
        //check(1,n);
        while(q--){
            scanf("%s",s);
            if(s[0]=='q'){
                int x,y;
                scanf("%d%d",&x,&y);
                printf("%lld\n",bit.sum(y)-bit.sum(x-1));
            }else{
                int x,y;
                scanf("%d%d",&x,&y);
                update(1,x,y,-1);
                while(1){
                    pair<int,int> pp=query(1,x,y);
                    if(pp.first!=0)break;
                    int now=pp.second;
                    bit.add(now);
                    update(1,now,now,a[now]);    
                }
            }    
        }
    }
    return 0;
}
