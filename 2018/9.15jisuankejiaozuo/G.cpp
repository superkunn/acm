#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
char s[200000];
int base[200000];
ll pow_mod(ll a,ll b,ll mod){//a^b
    ll res=1;
    for(;b;b>>=1){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
    }
    return res;
}
int main(){
    base[0]=2;
    for(int i=1;i<=100005;i++){
        base[i]=pow_mod(base[i-1],10,MOD);
    }
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        int len=strlen(s);
        ll ans=1;
        for(int i=0;i<len;i++){
            ans=ans*pow_mod(base[len-i-1],s[i]-'0',MOD)%MOD;
        }
        printf("%lld\n",ans*pow_mod(2,MOD-2,MOD)%MOD);
    }
    return 0;
}
