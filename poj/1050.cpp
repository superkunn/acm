#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=105;
int a[MAXN][MAXN];
int dp[MAXN];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ans=-1e9;
    for(int i=1;i<=n;i++){
        memset(dp,0,sizeof(dp));
        for(int j=i;j<=n;j++){
            int now=0;
            for(int k=1;k<=n;k++){
                dp[k]+=a[j][k];
                now+=dp[k];
                if(now<0)now=0;
                ans=max(ans,now);
            }
        }
    }
    printf("%d",ans);
    return 0;
}
