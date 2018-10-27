#include <algorithm>
#include  <iostream>
#include   <cstring>
#include    <string>
#include    <cstdio>
#include    <vector>
#include    <bitset>
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
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define SZ(x) ((int)(x).size())
typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
/*************head******************/
const int MAXN=6000+10;
int n;
int a[MAXN];
vi G[MAXN];
int dp[MAXN][2];
void dfs(int u,int p){
    dp[u][0]=0;
    dp[u][1]=a[u];
    for(auto v:G[u]){
        if(v==p)continue;
        dfs(v,u);
        dp[u][0]+=max(dp[v][0],dp[v][1]);
        dp[u][1]+=dp[v][0];
    }
}
int main(){
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",&a[i]);
    int x,y;
    while(scanf("%d%d",&x,&y),x+y){
        G[x].pb(y);
        G[y].pb(x);
    }
    dfs(1,-1);
    printf("%d",max(dp[1][0],dp[1][1]));
    return 0;
}
