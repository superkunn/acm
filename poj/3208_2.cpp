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
int bt[21];
ll dp[21][100];
bool vis[21][100];
ll dfs(int pos,int pre,bool limit){
    if(pos==0)return 1;
    if(!limit&&vis[pos][pre])return dp[pos][pre];
    int u=limit?bt[pos]:9;
    ll res=0;
    for(int d=0;d<=u;d++){
        if(pre==66&&d==6)continue;
        res+=dfs(pos-1,(pre%10)*10+d,limit&&d==bt[pos]);
    }
    if(!limit)dp[pos][pre]=res,vis[pos][pre]=true;
    return res;
}
ll gao(ll x){
    ll xx=x;
    int pos=0;
    while(x){
        bt[++pos]=x%10;
        x/=10;
    }
    return xx+1-dfs(pos,0,true);
}
int main(){
    memset(dp,-1,sizeof(dp));
    int n;
    scanf("%d",&n);
    while(n--){
        ll x;
        scanf("%lld",&x);
        ll l=1,r=1e18,ans;
        while(l<=r){
            ll mid=(l+r)>>1;
            if(gao(mid)>=x){
                ans=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
