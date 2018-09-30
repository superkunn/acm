#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5001;
int dp[MAXN+5][MAXN+5];
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    while(n--){
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);
        dp[x+1][y+1]=v;
    }
    for(int i=1;i<=MAXN;i++)
        for(int j=1;j<=MAXN;j++)
            dp[i][j]+=dp[i][j-1];
    for(int i=1;i<=MAXN;i++)
        for(int j=1;j<=MAXN;j++)
            dp[i][j]+=dp[i-1][j];
    int ans=0;
    for(int i=r;i<=MAXN;i++)
        for(int j=r;j<=MAXN;j++)
            ans=max(ans,dp[i][j]+dp[i-r][j-r]-dp[i][j-r]-dp[i-r][j]);
    printf("%d\n",ans);
    return 0;
}
