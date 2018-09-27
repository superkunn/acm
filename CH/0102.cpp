#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int main(){
    ll a,b,c;
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld",mul_mod(a,b,c));
    return 0;
}
