#include<bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define le l,m,lson
#define ri m+1,r,rson
#define mid m=(l+r)>>1
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e5+10;
const int INF=1e8;
int x[MAXN];
int now,sum;
int ans1[MAXN],ans2[MAXN];
int tree[MAXN<<2];
void push_up(int rt){
    tree[rt]=min(tree[lson],tree[rson]);
}
void build(int l,int r,int rt){
    if(l==r){
        scanf("%d",&tree[rt]);
        return;
    }
    int mid;
    build(le);
    build(ri);
    push_up(rt);
}
void update(int v,int l,int r,int rt){
    if(l==r){
        now-=tree[rt];
        tree[rt]=INF;
        return;
    }
    int mid;
    if(tree[lson]<=v)update(v,le);
    else update(v,ri);
    push_up(rt);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    build(1,n,1);
    int w;
    scanf("%d",&w);
    int bb=1;
    rep(i,1,w){
        scanf("%d",&x[i]);
        bb=max(x[i],bb);
    }
    now=0;
    sum=0;
    rep(i,1,bb){
        if(sum<n)now+=m;
        while(now>=tree[1]){
            sum++;
            update(now,1,n,1);
        }
        ans1[i]=sum;
        ans2[i]=now;
    }
    rep(i,1,w){
        printf("%d %d\n",ans1[x[i]],ans2[x[i]]);
    }
    return 0;
}
