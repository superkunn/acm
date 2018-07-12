#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
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
    int n;
    while(~scanf("%d",&n)){
        if(n==0)break;
        bool f=0;
        for(int i=2;i*i<n;i++){
            if(n%i==0){
                f=1;
                break;
            }
        }
        if(!f){
            printf("%d is normal.\n",n);
            continue;
        }
        for(int i=2;i<n;i++){
            if(pow_mod(i,n,n)!=i){
                f=0;
                break;
            }
        }
        if(f){
            printf("The number %d is a Carmichael number.\n",n);
        }
        else{
            printf("%d is normal.\n",n);
        }
    }
    return 0;
}
