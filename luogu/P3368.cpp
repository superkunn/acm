#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=5e5+10;
struct BIT{
    ll c[MAXN];
    int n;
    void init(int _n){
        n=_n;
        rep(i,1,n)c[i]=0;
    }
    void update(int pos,ll val){
        while(pos<=n){
            c[pos]+=val;
            pos+=pos&-pos;
        }
    }
    ll query(int pos){
        ll res=0;
        while(pos){
            res+=c[pos];
            pos-=pos&-pos;
        }
        return res;
    }
}bit;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    bit.init(n);
    rep(i,1,n){
        ll x;
        scanf("%lld",&x);
        bit.update(i,x);
        bit.update(i+1,-x);
    }
    while(m--){
        int op;
        scanf("%d",&op);
        if(op==1){
            int x,y;
            ll k;
            scanf("%d%d%lld",&x,&y,&k);
            bit.update(x,k);
            bit.update(y+1,-k);
        }else{
            int x;
            scanf("%d",&x);
            printf("%lld\n",bit.query(x));
        }
    }
    return 0;
}
