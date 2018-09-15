#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000+10;
int a[MAXN];
long long dp[MAXN][10];
long long pd[MAXN][10];
char op[10];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        scanf("%s",op+1);
        for(int i=0;i<=n;i++)dp[i][0]=k,pd[i][0]=k;
        for(int i=1;i<=n;i++){
            int x=i;
            if(x>m)x=m;
            for(int j=1;j<=x;j++){
                long long w;
                if(op[j]=='+'){
                    w=dp[i-1][j-1]+a[i];
                }else if(op[j]=='-'){
                    w=dp[i-1][j-1]-a[i];
                }else if(op[j]=='*'){
                    w=max(dp[i-1][j-1]*a[i],pd[i-1][j-1]*a[i]);
                }else{
                    w=max(dp[i-1][j-1]/a[i],pd[i-1][j-1]/a[i]);
                }
                if(i==j)dp[i][j]=w;
                else dp[i][j]=max(dp[i-1][j],w);

                if(op[j]=='+'){
                    w=pd[i-1][j-1]+a[i];
                }else if(op[j]=='-'){
                    w=pd[i-1][j-1]-a[i];
                }else if(op[j]=='*'){
                    w=min(dp[i-1][j-1]*a[i],pd[i-1][j-1]*a[i]);
                }else{
                    w=min(dp[i-1][j-1]/a[i],pd[i-1][j-1]/a[i]);
                }
                if(i==j)pd[i][j]=w;
                else pd[i][j]=min(pd[i-1][j],w);
            }
        }
        printf("%lld\n",dp[n][m]);
    }

    return 0;
}
