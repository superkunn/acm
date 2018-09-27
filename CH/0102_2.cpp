#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul_mod(ll a,ll b,ll mod){
    a%=mod;
    b%=mod;
    ll c=(long double)a*b/mod;
    ll ans=a*b-c*mod;
    if(ans<0)ans+=mod;
    else if(ans>mod)ans-=mod;
    return ans;
}
int main(){
    ll a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld",mul_mod(a,b,c));
    return 0;
}
