#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include     <stack>
#include     <queue>
#include     <cmath>
#include       <set>
#include       <map>
using namespace std;
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define clr(a,x) memset(a,x,sizeof(a))
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
int dp[6455][85][85],mod;
void update(int &x,ll y){
    if(y+x>mod){
        x=(y+x)%mod;
    }else x=y+x;
}
int work(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d%d",&n,&m,&mod);
        dp[1][1][1]=n*m;
        rep(k,2,n*m){
            rep(i,1,n){
                rep(j,1,m){
                    if(i+j>k+1)break;
                    dp[k][i][j]=0;
                    update(dp[k][i][j],1LL*dp[k-1][i][j-1]*(i*(m-(j-1))));
                    update(dp[k][i][j],1LL*dp[k-1][i-1][j]*(j*(n-(i-1))));
                    update(dp[k][i][j],1LL*dp[k-1][i][j]*(i*j-(k-1)));
                }
            }
        }
        printf("%d\n",dp[n*m][n][m]%mod);
    }
    return 0;
}
int main(){
#ifdef superkunn
    freopen("input.txt","rt",stdin);
#endif
    work();
    return 0;
}
