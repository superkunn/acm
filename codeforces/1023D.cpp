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
const int MAXN=2e5+10;
int st[MAXN];
int ed[MAXN];
int a[MAXN];
int b[MAXN];
int tree[MAXN<<2];
void push_down(int rt){
    int w=tree[rt];
    if(w){
		tree[lson]=w;
		tree[rson]=w;
        tree[rt]=0;
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
   	if(R>m) update(L,R,v,ri);
}
int query(int pos,int l,int r,int rt){
	if(l==r){
		return tree[rt];
	}
	int mid;
	push_down(rt);
	if(pos<=m)return query(pos,le);
	else return query(pos,ri);
}
int work(){
	int n,q;
	scanf("%d%d",&n,&q);
	rep(i,1,n){
		scanf("%d",&a[i]);
		if(!st[a[i]]){
			st[a[i]]=i;
		}
		ed[a[i]]=i;
	}
	rep(i,1,q){
		if(st[i]){
			update(st[i],ed[i],i,1,n,1);
		}	
	}
	bool f=1;
	rep(i,1,n){
		b[i]=query(i,1,n,1);
		if(a[i]&&a[i]!=b[i]){
			puts("NO");
			return 0;
		}
		if(a[i]==0)f=0;
	}
	if(f&&!st[q]){
		puts("NO");
		return 0;
	}
	puts("YES");
	if(!st[q]){
		rep(i,1,n){
			if(!a[i]){
				b[i]=q;
				break;
			}
		}
	}
	rep(i,2,n){
		if(b[i]==0){
			b[i]=b[i-1];
		}
	}
	per(i,n-1,1){
		if(b[i]==0){
			b[i]=b[i+1];
		}
	}
	rep(i,1,n)printf("%d ",b[i]);
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
