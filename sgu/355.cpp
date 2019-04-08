#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1e4+10;
int ans[MAXN],v[MAXN],prime[MAXN],cnt;
void primes(int n){
    rep(i,2,n){
        if(v[i]==0){
            v[i]=i;
            prime[++cnt]=i;
            ans[i]=2;
        }
        rep(j,1,cnt){
            if(prime[j]>v[i]||prime[j]>n/i)break;
            v[i*prime[j]]=prime[j];
            ans[i*prime[j]]=ans[i]+1;
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    primes(n);
    ans[1]=1;
    int mx=1;
    rep(i,1,n){
        mx=max(mx,ans[i]);
    }
    printf("%d\n",mx);
    rep(i,1,n){
        printf("%d ",ans[i]);
    }
    return 0;
}
