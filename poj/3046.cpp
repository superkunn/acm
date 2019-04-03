#include<cstdio>
#include<iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
const int MAXN=1000+10;
const int MAXM=1e5+10;
const int MOD=1e6;
int cnt[MAXN];
int dp[MAXN][MAXM];
int main(){
    int t,a,s,b;
    scanf("%d%d%d%d",&t,&a,&s,&b);
    rep(i,1,a){
        int x;
        scanf("%d",&x);
        cnt[x-1]++;
    }
    rep(i,0,t){
        dp[i][0]=1;
    }
    rep(i,0,t-1){
        rep(j,1,b){
            if(j-1-cnt[i]>=0){
                dp[i+1][j]=(dp[i+1][j-1]+dp[i][j]-dp[i][j-1-cnt[i]]+MOD)%MOD;
            }else{

                dp[i+1][j]=(dp[i+1][j-1]+dp[i][j])%MOD;
            }
        }
    }
    int ans=0;
    rep(i,s,b){
        ans=(ans+dp[t][i])%MOD;
    }

    printf("%d",ans);

    return 0;
}
