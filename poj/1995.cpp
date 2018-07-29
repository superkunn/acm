#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
typedef long long ll;
ll pow_mod(ll a,ll i,ll mod){
    ll res=1;
    while(i>0){
        if(i&1)res=res*a%mod;
        a=a*a%mod;
        i>>=1;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        ll mod;
        int n;
        scanf("%lld%d",&mod,&n);
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll a,b;
            scanf("%lld%lld",&a,&b);
            ans+=pow_mod(a,b,mod);
            ans=ans%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
