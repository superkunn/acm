#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
const int MOD=1e9+7;
int dp[MAXN][12][2048];
int a[MAXN];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        memset(dp,0,sizeof(dp));
        int n,d;
        scanf("%d%d",&n,&d);
        d=min(n,d);
        int ans=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ans^=a[i];
        }
        for(int i=1;i<=n;i++){
            dp[i][0][0]=1;
            for(int j=1;j<=d&&j<=i;j++){
                for(int k=0;k<2048;k++){
                    if(i==1)dp[i][j][a[i]]=1;
                    else dp[i][j][k]=(1LL*dp[i-1][j][k]+1LL*dp[i-1][j-1][k^a[i]])%MOD;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<=d;i++){
            cnt=(1LL*cnt+1LL*dp[n][i][ans])%MOD;
        }
        printf("%d\n",cnt);
    }
    return 0;
}
