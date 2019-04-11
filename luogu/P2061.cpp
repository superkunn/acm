#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define lson rt<<1
#define rson rt<<1|1
#define pb push_back
typedef vector<int> vi;
typedef long long ll;
const int MAXN=1e5+10;

vi dv;
int dinit(){
    sort(dv.begin(),dv.end());
    dv.erase(unique(dv.begin(),dv.end()),dv.end());
    return dv.size();
}
int getid(int x){
    return lower_bound(dv.begin(),dv.end(),x)-dv.begin()+1;
}
int getval(int x){
    return dv[x-1];
}

int a[MAXN],b[MAXN],c[MAXN];
int tree[MAXN<<2];
void push_down(int rt){
    tree[lson]=max(tree[rt],tree[lson]);
    tree[rson]=max(tree[rt],tree[rson]);
}
void update(int L,int R,int val,int l,int r,int rt){
    if(L<=l&&r<=R){
        tree[rt]=max(tree[rt],val);
        return;
    }
    push_down(rt);
    int mid=(l+r)>>1;
    if(mid>=L)update(L,R,val,l,mid,lson);
    if(mid+1<=R)update(L,R,val,mid+1,r,rson);
}
int query(int pos,int l,int r,int rt){
    if(l==r)return tree[rt];
    push_down(rt);
    int mid=(l+r)>>1;
    if(pos<=mid)query(pos,l,mid,lson);
    else query(pos,mid+1,r,rson);
}
int main(){
    int n;
    scanf("%d",&n);
    rep(i,1,n){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        dv.pb(a[i]);
        dv.pb(b[i]);
    }
    int tot=dinit();
    rep(i,1,n){
        update(getid(a[i]),getid(b[i])-1,c[i],1,tot,1);
    }
    ll ans=0;
    rep(i,1,tot-1){
        ans+=1LL*query(i,1,tot,1)*(getval(i+1)-getval(i));
    }
    printf("%lld",ans);
    return 0;
}
