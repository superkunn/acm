#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
int mm[1005][3];
int dp[1005][33];
int main(){
    int t,w;
    scanf("%d%d",&t,&w);
    for(int i=1;i<=t;i++){
        int x;
        scanf("%d",&x);
        mm[i][x]=1;
    }
    for(int i=1;i<=t;i++){
        dp[i][0]=dp[i-1][0]+mm[i][1];
    }
    for(int j=1;j<=w;j++){
        for(int i=1;i<=t;i++){
            dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+mm[i][j%2+1];
        }
    }
    int ans=-1;
    for(int j=0;j<=w;j++){
        ans=max(dp[t][j],ans);
    }
    printf("%d",ans);
    return 0;
}
