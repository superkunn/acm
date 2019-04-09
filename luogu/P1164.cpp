#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
typedef long long ll;
const int MAXN=1e4+10;
ll dp[MAXN];
int main(){
    int n,m;
    scanf("%d%d",&m,&n);
    dp[0]=1;
    rep(i,1,m){
        int x;
        scanf("%d",&x);
        per(j,n,1){
            if(j-x<0)continue;
            dp[j]+=dp[j-x];
        }
    }
    printf("%lld",dp[n]);
    return 0;
}
