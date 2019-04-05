#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=2e5+10;
int a[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    int cnt=0;
    rep(i,1,n){
        scanf("%d",&a[i]);
        if(a[i]>0){
            cnt++;
        }
    }
    int ans=0;
    if(cnt==0){
        ans=a[1];
        rep(i,1,n){
            ans=max(ans,a[i]);
        }
        printf("%d",ans);
        return 0;
    }
    int l=0;
    int sum=0;
    while(l<=n){
        l++;
        sum+=a[l];
        if(sum<=0){
            sum=0;
        }
        ans=max(ans,sum);
    }
    printf("%d",ans);
    return 0;
}
