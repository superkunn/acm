#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
typedef pair<int,int> pii;
const int MAXN=2e5+10;
int v[MAXN],prime[MAXN],cnt;
void primes(int n){
    memset(v,0,sizeof(v));
    cnt=0;
    rep(i,2,n){
        if(v[i]==0){
            v[i]=i;
            prime[++cnt]=i;
        }
        rep(j,1,cnt){
            if(prime[j]>v[i]||prime[j]>n/i)break;
            v[i*prime[j]]=prime[j];
        }
    }
}
unordered_map<int,pii> mmp;
int main(){
    int n;
    scanf("%d",&n);
    primes(n);
    rep(i,1,cnt){
        rep(j,i,cnt){
            if(mmp.count(prime[i]+prime[j])!=0)continue;
            mmp[prime[i]+prime[j]]={prime[i],prime[j]};
        }
    }
    rep(i,1,n){
        if(v[i]!=i)continue;
        if(mmp.count(n-i)!=0){
            printf("%d %d %d",i,mmp[n-i].first,mmp[n-i].second);
            break;
        }
    }
    return 0;
}
