#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=22;
int a[MAXN][MAXN];
int dp[1<<21][MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    rep(i,1,n)rep(j,1,n)cin>>a[i][j];
    int ed=1<<n;
    ed--;
    memset(dp,0x3f,sizeof(dp));
    dp[1][0]=0;
    rep(i,1,ed){
        for(int j=0;j<n;j++)if(i>>j&1){
            for(int k=0;k<n;k++)if((i^1<<j)>>k&1){
                dp[i][j]=min(dp[i][j],dp[i^1<<j][k]+a[k+1][j+1]);
            }
        }
    }
    cout<<dp[ed][n-1]<<endl;
    return 0;
}
