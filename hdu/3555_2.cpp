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
ll dp[21][2];
ll dfs(int pos,int pre,bool limit){
    if(pos==0)return 1;
    if(!limit&&dp[pos][pre==4]!=-1)return dp[pos][pre==4];
    int u=limit?bt[pos]:9;
    ll res=0;
    for(int i=0;i<=u;i++){
        if(pre==4&&i==9)continue;
        res+=dfs(pos-1,i,limit&&i==bt[pos]);
    }
    if(!limit)dp[pos][pre==4]=res;
    return res;
}
ll gao(ll x){
    int pos=0;
    while(x){
        bt[++pos]=x%10;
        x/=10;
    }
    return dfs(pos,0,true);
}
int main(){
    int T;
    scanf("%d",&T);
    clr(dp,-1);
    while(T--){
        ll x;
        scanf("%lld",&x);
        printf("%lld\n",x-gao(x)+1);
    }
    return 0;
}
