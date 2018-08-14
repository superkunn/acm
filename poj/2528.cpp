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
const int MAXN=2e4+10;
struct node{
    int v,id;
}no[MAXN];
bool cmp(node x,node y){
    return x.v<y.v;
}
int x[MAXN];
bool vis[MAXN];
int T,n,ans;
int tree[MAXN<<2];
void push_down(int rt){
    if(tree[rt]!=-1){
        tree[lson]=tree[rson]=tree[rt];
        tree[rt]=-1;
    }
}
void update(int L,int R,int v,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[rt]=v;
        return;
    }
    push_down(rt);
    int mid;
    if(L<=m)update(L,R,v,le);
    if(R>m)update(L,R,v,ri);
}
void query(int l,int r,int rt){
    if(tree[rt]!=-1){
        if(!vis[tree[rt]]){
            ans++;
            vis[tree[rt]]=true;
        }
        return;
    }
    if(l==r)return;
    int mid;
    query(le);
    query(ri);
}
int work(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        rep(i,1,n){
            scanf("%d%d",&no[i].v,&no[i+n].v);
            no[i].id=i;
            no[i+n].id=i+n;
        }
        sort(no+1,no+1+2*n,cmp);
        int tot=1;
        x[no[1].id]=1;
        rep(i,2,2*n){
            if(no[i].v!=no[i-1].v)tot++;
            x[no[i].id]=tot;
        }
        clr(tree,-1);
        rep(i,1,n){
            update(x[i],x[i+n],i,1,tot,1);
        }
        ans=0;
        clr(vis,0);
        query(1,tot,1);
        printf("%d\n",ans);
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
