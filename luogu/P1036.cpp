#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
int a[30];
ll mul_mod(ll a,ll b,ll mod){
    a%=mod;
    b%=mod;
    ll c=(long double)a*b/mod;
    ll ans=a*b-c*mod;
    if(ans<0)ans+=mod;
    else if(ans>mod)ans-=mod;
    return ans;
}
ll pow_mod(ll a,ll b,ll mod){//a^b
    ll res=1%mod;
    while(b){
        if(b&1)res=mul_mod(res,a,mod);
        a=mul_mod(a,a,mod);
        b>>=1;
    }
    return res;
}
bool Miller_Rabin(ll n, int s){//s is testing frequency . true -> n is prime
    if (n == 2) return 1;
    if (n < 2 || !(n & 1)) return 0;
    int t = 0;
    ll  x, y, u = n - 1;
    while ((u & 1) == 0) t++, u >>= 1;
    for (int i = 0; i < s; i++){
        ll a = rand() % (n - 1) + 1;
        ll x = pow_mod(a, u, n);
        for (int j = 0; j < t; j++){
            ll y = mul_mod(x, x, n);
            if (y == 1 && x != 1 && x != n - 1) return 0;
            x = y;
        }
        if (x != 1) return 0;
    }
    return 1;
}
int n;
int fun(int lft,int sum,int p){
    if(lft==0)return Miller_Rabin(sum,15);
    int res=0;
    for(int i=p;i<=n;i++){
        res+=fun(lft-1,sum+a[i],i+1);
    }
    return res;
}
int main(){
    int k;
    scanf("%d%d",&n,&k);
    rep(i,1,n){
        scanf("%d",&a[i]);
    }
    printf("%d",fun(k,0,1));
    return 0;
}
