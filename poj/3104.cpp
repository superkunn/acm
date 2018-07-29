#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const long long INF=1LL<<60;
const int MAXN=1e5+5;
int n,k,a[MAXN];
bool check(long long x){
    long long w=0;
    for(int i=1;i<=n;i++){
        long long now=1LL*a[i]-x;
        if(now<=0)continue;
        w+=(now+1LL*k-2LL)/(1LL*(k-1));
        if(w>x)return false;
    }
    return true;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    if(k==1){
        int res=0;
        for(int i=1;i<=n;i++)res=max(res,a[i]);
        printf("%d",res);
        return 0;
    }
    long long l=1,r=INF,ans;
    while(l<=r){
        long long mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    printf("%lld",ans);
    return 0;
}
