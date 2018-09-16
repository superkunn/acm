#include<bits/stdc++.h>
using namespace std;
long long dp[35];
int main(){
    int n;
    scanf("%d",&n);
    dp[0]=dp[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    printf("%I64d %d",dp[n],n+1);
    return 0;
}
