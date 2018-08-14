#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
#define lson rt<<1
#define rson rt<<1|1
#define le l,m,lson
#define ri m+1,r,rson
#define mid m=(l+r)>>1
const int MAXN=1e5+10;
int n,x,y,z;
int tree[MAXN<<2],lazy[MAXN<<2];
void push_up(int rt){
    tree[rt]=tree[lson]+tree[rson];
}
void push_down(int rt,int len){
    int w=lazy[rt];
    if(w){
        lazy[lson]=lazy[rson]=w;
        tree[lson]=(len-(len>>1))*w;
        tree[rson]=(len>>1)*w;
        lazy[rt]=0;
    }
}
void build(int l,int r,int rt){
    tree[rt]=1;
    lazy[rt]=0;
    if(l==r)return;
    int mid;
    build(le);
    build(ri);
    push_up(rt);
}
void update(int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        lazy[rt]=v;
        tree[rt]=(r-l+1)*v;
        return;
    }
    push_down(rt,r-l+1);
    int mid;
    if(L<=m)update(L,R,v,le);
    if(R>m)update(L,R,v,ri);
    push_up(rt);
}
int work(){
    int T;
    scanf("%d",&T);
    rep(kase,1,T){
        scanf("%d",&n);
        build(1,n,1);
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%d%d%d",&x,&y,&z);
            update(x,y,z,1,n,1);
        }
        printf("Case %d: The total value of the hook is %d.\n",kase,tree[1]);
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
