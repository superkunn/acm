#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
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
#define lson rt<<1
#define rson rt<<1|1
#define le l,m,lson
#define ri m+1,r,rson
#define mid m=(l+r)>>1
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=2e5+5;
int tree[MAXN<<2];
void push_up(int rt){
    tree[rt]=max(tree[lson],tree[rson]);
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
void update(int p,int v,int l,int r,int rt){
    if(l==r){
        tree[rt]=v;
        return;
    }
    int mid;
    if(p<=m)update(p,v,le);
    else update(p,v,ri);
    push_up(rt);
}
int query(int L,int R,int l,int r,int rt){
    if(L<=l&&r<=R){
        return tree[rt];
    }
    int mid;
    int ret=0;
    if(L<=m)ret=max(ret,query(L,R,le));
    if(R>m)ret=max(ret,query(L,R,ri));
    return ret;
}
char op[5];
int x,y;
int work(){
    int N,M;
    while(scanf("%d%d",&N,&M)!=EOF){
        build(1,N,1);
        while(M--){
            scanf("%s%d%d",op,&x,&y);
            if(op[0]=='Q'){
                printf("%d\n",query(x,y,1,N,1));
            }else{
                update(x,y,1,N,1);
            }
        }
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
