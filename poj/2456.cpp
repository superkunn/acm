#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<iostream>
using namespace std;
const int MAXN=1e5+5;
const int INF=1e9;
int a[MAXN];
int n,c;
bool check(int x){
    int now=a[1];
    int cnt=1;
    for(int i=2;i<=n;i++){
        if(now+x<=a[i]){
            cnt++;
            now=a[i];
        }
        if(cnt==c)break;
    }
    if(cnt==c)return true;
    else return false;
}
int main(){
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
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
