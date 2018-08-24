#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul_mod(ll a,ll b,ll mod){
    ll res=0;
    for(;b;b>>=1){
        if(b&1)res=(res+a)%mod;
        a=(a<<1)%mod;
    }
    return res;
}
ll pow_mod(ll a,ll b,ll mod) {
    ll res=1;
    for(;b;b>>=1){
        if(b&1)res=mul_mod(res,a,mod);
        a=mul_mod(a,a,mod);
    }
    return res;
}
int main(){
    ll n,p;
    while(~scanf("%lld%lld",&n,&p)){
        printf("%lld\n",(pow_mod(2,n,p)-2+p)%p);
    }
    return 0;
}
