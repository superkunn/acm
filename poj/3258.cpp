#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN=5e4+5;
const int INF=1e9+5;
int len,n,m;
int a[MAXN];
bool check(int x){
    int cnt=0;
    int now=0;
    for(int i=1;i<=n;i++){
        if(now+x>a[i]){
            cnt++;
        }else{
            now=a[i];
        }
    }
    if(cnt>m){
        return false;
    }else{
        return true;
    }
}
int main(){
    scanf("%d%d%d",&len,&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    n++;
    a[n]=len;
    int l=1,r=INF,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    printf("%d",ans);
    return 0;
}
