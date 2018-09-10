#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define clr(a,x) memset(a,x,sizeof(a))
typedef long long ll;
const int MAXN=1e5+10;
struct BIT{
    int n;
    ll c[MAXN];
    ll b[MAXN];
    void init(int _n){
        n=_n;
        clr(c,0);
        clr(b,0);
    }
    void add(int i,ll v){
        ll d=v-b[i];
        b[i]=v;
        for(;i<=n;i+=i&-i)c[i]+=d;
    }
    ll sum(int i){
        ll res=0;
        for(;i;i-=i&-i){
            res+=c[i];
        }
        return res;
    }
    ll query(int l,int r){
        if(r<l)return 0;
        else return sum(r)-sum(l-1);
    }
}bit[2];
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    bit[0].init(n);
    bit[1].init(n);
    rep(i,1,n){
        int x;
        scanf("%d",&x);
        bit[0].add(i,x);
        bit[1].add(i,1LL*x*(n-i+1));
    }
    while(q--){
        int op,x,y;
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            ll ans=bit[1].query(x,y);
            ans-=bit[0].query(x,y)*(n-y);
            printf("%lld\n",ans);
        }else{
            bit[0].add(x,y);
            bit[1].add(x,1LL*(n-x+1)*y);
        }
    }
    return 0;
}
