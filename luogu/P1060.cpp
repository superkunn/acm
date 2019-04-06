#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
const int MAXN=3e4+10;
int dp[MAXN];
int a[30],b[30];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    rep(i,1,m){
        scanf("%d%d",&a[i],&b[i]);
    }
    rep(i,1,m){
        per(j,n,1){
            if(j-a[i]>=0){
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]*b[i]);
            }
        }
    }
    printf("%d",dp[n]);
    return 0;
}
