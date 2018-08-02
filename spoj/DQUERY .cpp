
#include<cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
const int MAXN=5e5+7;
int n,q,a[MAXN],root[MAXN*2],head[MAXN],nxt[MAXN],edt[MAXN],cnt,x,y;
struct node{int l,r,sum;}T[MAXN*40];
vi v;
int getid(int x){return lower_bound(all(v),x)-v.begin()+1;}
void update(int l,int r,int &x,int y,int pos ,int v){
    x=++cnt;
    T[x]=T[y];
    T[x].sum+=v;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)update(l,mid,T[x].l,T[y].l,pos,v);
    else update(mid+1,r,T[x].r,T[y].r,pos,v);
}
int query(int l,int r,int x,int y,int f){
    if(x<=l&&r<=y)return T[f].sum;
    int mid=(l+r)>>1;
    int ans=0;
    if(x<=mid)ans+=query(l,mid,x,y,T[f].l);
    if(y>mid)ans+=query(mid+1,r,x,y,T[f].r);
    return ans;
}
int work(){
    scanf("%d",&n);
    memset(head,-1,sizeof(head));
    rep(i,1,n)scanf("%d",&a[i]),v.pb(a[i]);
    sort(all(v));v.erase(unique(all(v)),v.end());
    rep(i,1,n){
        int id=getid(a[i]);
        nxt[i]=head[id];
        head[id]=i;
    }
    int now=0;
    rep(i,1,n){
        now++;
        update(1,n,root[now],root[now-1],i,1);
        if(nxt[i]!=-1)now++,update(1,n,root[now],root[now-1],nxt[i],-1);
        edt[i]=root[now];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d%d",&x,&y);
        printf("%d\n",query(1,n,x,y,edt[y]));
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
