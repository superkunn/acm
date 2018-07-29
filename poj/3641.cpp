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
bool check(int x){
    if(x==1)return false;
    int w=sqrt(x);
    for(int i=2;i<=w;i++){
        if(i==x)break;
        if(x%i==0)return false;
    }
    return true;
}
int main(){
    ll p,a;
    while(~scanf("%lld%lld",&p,&a)){
        if(p==0&&a==0)break;
        if(pow_mod(a,p,p)==a%p&&!check(p))puts("yes");
        else puts("no");
    }
    return 0;
}
