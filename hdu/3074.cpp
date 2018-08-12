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
const int MAXN=5e4+5;
const int MOD=1e9+7;
ll powmod(ll a,ll i){
    ll res=1;
    while(i>0){
        if(i&1)res=res*a%MOD;
        a=a*a%MOD;
        i>>=1;
    }
    return res;
}
ll c[MAXN];
int n,m,op,x,y;
void init(){
    rep(i,0,n)c[i]=1;
}
void update(int i,int x){
    for(;i<=n;i+=i&-i){
        c[i]=(c[i]*x)%MOD;   
    }
}
ll query(int i){
    ll s=1;
    for(;i;i-=i&-i){
        s=(s*c[i])%MOD;
    }
    return s;
}
int work(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        init();
        rep(i,1,n){
            int x;
            scanf("%d",&x);
            update(i,x);
        }
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&op,&x,&y);
            if(op==0){
                ll w2=query(y);
                ll w1=query(x-1);
                w1=powmod(w1,MOD-2);
                printf("%lld\n",(w1*w2)%MOD);
            }else{
                ll w2=query(x);
                ll w1=query(x-1);
                w1=powmod(w1,MOD-2);
                ll w3=(w1*w2)%MOD;
                w3=powmod(w3,MOD-2);
                w3=(w3*y)%MOD;
                update(x,w3);
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
