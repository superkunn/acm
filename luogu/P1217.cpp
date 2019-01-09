#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define what_is(x) cerr<<#x<<" is "<<x<<endl
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
int base[10];
int fun(int x,int pos){
    return (x/base[pos])%10;
}
vector<int> ans;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    base[1]=1;
    rep(i,2,8){
        base[i]=base[i-1]*10;
    }
    ans.pb(2);
    ans.pb(3);
    ans.pb(5);
    ans.pb(7);
    rep(i,1,8){
        if(i&1){
            int w=i/2;
            for(int j=1;j<base[w+1];j+=2){
                rep(k,0,9){
                    int now=j+base[w+1]*k;
                    rep(kk,1,w){
                        int p=i-kk+1;
                        now+=base[p]*fun(j,kk);
                    }
                    if(Miller_Rabin(now,15)){
                            ans.pb(now);
                    }
                }
            }
        }else{
            int w=i/2;
            for(int j=1;j<base[w+1];j+=2){
                int now=j;
                rep(kk,1,w){
                    int p=i-kk+1;
                    now+=base[p]*fun(j,kk);
                }
                if(Miller_Rabin(now,15)){
                    ans.pb(now);
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    for(auto x:ans){
        if(a<=x&&x<=b){
            printf("%d\n",x);
        }
    }
    return 0;
}
