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
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
#define lson rt<<1
#define rson rt<<1|1
#define le l,m,lson
#define ri m+1,r,rson
#define mid m=(l+r)>>1;
const int MAXN=2e5+5;
int h,w,n;
int tree[MAXN<<2];
void push_up(int rt){
    tree[rt]=max(tree[lson],tree[rson]);
}
void build(int l,int r,int rt){
    tree[rt]=w;
    if(l==r){
        return;
    }
    int mid;
    build(le);
    build(ri);
}
int query(int x,int l,int r,int rt){
    if(l==r){
        tree[rt]-=x;
        return l;
    }
    int mid;
    int res=tree[lson]>=x?query(x,le):query(x,ri);
    push_up(rt);
    return res;
}
int work(){
    while(~scanf("%d%d%d",&h,&w,&n)){
        if(h>n)h=n;
        build(1,h,1);
        while(n--){
            int x;
            scanf("%d",&x);
            if(tree[1]<x)puts("-1");
            else printf("%d\n",query(x,1,h,1));
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
