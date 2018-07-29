#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
const long long INF=1LL<<62;
int n,m;
int a[MAXN];
bool check(long long x){
    int cnt=1;
    long long now=0;
    for(int i=1;i<=n;i++){
        if(now+a[i]<=x){
            now+=a[i];
        }else{
            cnt++;
            now=a[i];
        }
    }
    if(cnt<=m)return true;
    else return false;
}
int main(){
    scanf("%d%d",&n,&m);
    int w=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        w=max(w,a[i]);
    }
    long long l=w,r=INF,ans;
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
