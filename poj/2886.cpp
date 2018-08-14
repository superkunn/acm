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
#define mid m=(l+r)>>1
const int MAXN=5e5+10;
int N,K,n;
char _name[MAXN][15];
int a[MAXN],ans[MAXN];
int tree[MAXN<<2];
void push_up(int rt){
    tree[rt]=tree[lson]+tree[rson];
}
void build(int l,int r,int rt){
    if(l==r){
        tree[rt]=1;
        return;
    }
    int mid;
    build(le);
    build(ri);
    push_up(rt);
}
pii query(int k,int l,int r,int rt){
    if(l==r){
        tree[rt]=0;
        return mp(l,0);
    }
    int mid;
    pii now;
    if(tree[lson]>=k)now=query(k,le);
    else now=query(k-tree[lson],ri);
    push_up(rt);
    if(now.fi>m)now.se+=tree[lson];
    return now;
}
void pre(){
    clr(ans,0);
    rep(i,1,N){
        ans[i]++;
        for(int j=2*i;j<=N;j+=i){
            ans[j]++;
        }
    }
    int mx=ans[1];
    n=1;
    rep(i,2,N){
        if(ans[i]>mx){
            mx=ans[i];
            n=i;
        }
    }
}
int work(){
    while(~scanf("%d%d",&N,&K)){
        pre();
        rep(i,1,N){
            scanf("%s%d",_name[i],&a[i]);
        }
        build(1,N,1);
        pii now;
        int pos,kth;
        now=query(K,1,N,1);
        pos=now.fi;
        kth=now.se;
        rep(i,1,n-1){
            int sum=tree[1];
            if(a[pos]<0){
                pos=((kth+a[pos])%sum+sum)%sum+1;
            }else{
                pos=((kth+a[pos]-1)%sum+sum)%sum+1;
            }
            now=query(pos,1,N,1);  
            pos=now.fi;
            kth=now.se;
        }
        printf("%s %d\n",_name[pos],ans[n]);
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
