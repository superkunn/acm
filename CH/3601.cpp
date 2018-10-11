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
const int MOD=10007;
void add(ll &a,ll b,ll mod){
    a+=b;
    a%=mod;
}
ll mul_mod(ll a,ll b,ll mod){
    ll res=0;
    while(b){
        if(b&1)add(res,a,mod);
        add(a,a,mod);
        b>>=1;
    }
    return res;
}
/*
ll mul_mod(ll a,ll b,ll mod){
    a%=mod;
    b%=mod;
    ll c=(long double)a*b/mod;
    ll ans=a*b-c*mod;
    if(ans<0)ans+=mod;
    else if(ans>mod)ans-=mod;
    return ans;
}
*/
ll pow_mod(ll a,ll b,ll mod){//a^b
    ll res=1%mod;
    while(b){
        if(b&1)res=mul_mod(res,a,mod);
        a=mul_mod(a,a,mod);
        b>>=1;
    }
    return res;
}
ll C(int x,int y){
    ll res=1;
    for(int i=1;i<=y;i++){
        res=res*i%MOD;
    }
    ll inv=1;
    for(int i=1;i<=x;i++){
        inv=inv*i%MOD;
    }
    for(int i=1;i<=(y-x);i++){
        inv=inv*i%MOD;
    }
    inv=pow_mod(inv,MOD-2,MOD);
    return res*inv%MOD;
}
int main(){
	int a,b,k,n,m;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	ll ans=1;
	ans=(ans*pow_mod(a,n,MOD))%MOD;
	ans=(ans*pow_mod(b,m,MOD))%MOD;
	ans=(ans*C(n,k))%MOD;
	printf("%lld",ans);
	return 0;
}


